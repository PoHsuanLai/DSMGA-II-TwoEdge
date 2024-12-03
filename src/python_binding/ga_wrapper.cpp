#include <pybind11/pybind11.h>
#include <pybind11/functional.h>
#include <pybind11/stl.h>
#include "dsmga2.h"
#include "chromosome.h"
#include "fitness_functions.h"

namespace py = pybind11;

class PyOptimizer {
private:
    int problemSize;
    int populationSize;
    int maxGenerations;
    int maxEvaluations;
    std::function<double(const std::vector<int>&)> customObjectiveFunction;
    FitnessType fitnessType;
    bool useCustomFunction;

public:
    PyOptimizer(int problem_size, 
                int population_size = 100,
                int max_generations = 1000,
                int max_evaluations = -1,
                const std::string& fitness_type = "custom") 
        : problemSize(problem_size)
        , populationSize(population_size)
        , maxGenerations(max_generations)
        , maxEvaluations(max_evaluations)
        , useCustomFunction(false) {
        
        std::map<std::string, FitnessType> fitnessMap = {
            {"onemax", FITNESS_ONEMAX},
            {"mktrap", FITNESS_MKTRAP},
            {"ftrap", FITNESS_FTRAP},
            {"cyctrap", FITNESS_CYCTRAP},
            {"nk", FITNESS_NK},
            {"sat", FITNESS_SAT},
            {"custom", FITNESS_CUSTOM}
        };

        std::string type_lower = fitness_type;
        std::transform(type_lower.begin(), type_lower.end(), type_lower.begin(), ::tolower);

        auto it = fitnessMap.find(type_lower);
        if (it != fitnessMap.end()) {
            fitnessType = it->second;
            useCustomFunction = (fitnessType == FITNESS_CUSTOM);
        } else {
            throw std::invalid_argument("Invalid fitness type");
        }
    }

    void set_objective_function(const std::function<double(const std::vector<int>&)>& func) {
        if (!useCustomFunction) {
            throw std::runtime_error("Cannot set objective function when using predefined fitness type");
        }
        customObjectiveFunction = func;
    }

    std::pair<std::vector<int>, double> optimize() {
        std::function<double(const Chromosome&)> fitnessFunc;
        
        if (useCustomFunction) {
            if (!customObjectiveFunction) {
                throw std::runtime_error("Custom objective function not set");
            }
            fitnessFunc = [this](const Chromosome& ch) {
                std::vector<int> x(problemSize);
                for (int i = 0; i < problemSize; i++) {
                    x[i] = ch.getVal(i);
                }
                return this->customObjectiveFunction(x);
            };
        } else {
            fitnessFunc = getFitnessFunction(fitnessType);
        }

        DSMGA2 ga(problemSize, populationSize, maxGenerations, maxEvaluations, fitnessFunc);
        ga.doIt(false);

        return {ga.getBest(), ga.getBestFitness()};
    }

    // Add sweep member function
    py::dict sweep(int min_pop = 10, int max_pop = 200, int step_size = 30) {
        std::function<double(const Chromosome&)> fitnessFunc;
        if (useCustomFunction) {
            if (!customObjectiveFunction) {
                throw std::runtime_error("Custom objective function not set");
            }
            fitnessFunc = [this](const Chromosome& ch) {
                std::vector<int> x(problemSize);
                for (int i = 0; i < problemSize; i++) {
                    x[i] = ch.getVal(i);
                }
                return this->customObjectiveFunction(x);
            };
        } else {
            fitnessFunc = getFitnessFunction(fitnessType);
        }

        auto start_time = std::chrono::steady_clock::now();

        // Initialize records for bisection search
        struct Record {
            int n;
            double nfe;
            double gen;
        };
        
        Record rec[3];
        rec[0].n = min_pop;
        rec[1].n = min_pop + step_size;
        rec[2].n = min_pop + 2 * step_size;

        // Phase 1: Initial evaluation of three population sizes
        for (int i = 0; i < 3; ++i) {
            DSMGA2 ga(problemSize, rec[i].n, maxGenerations, maxEvaluations, fitnessFunc);
            int gens = ga.doIt(false);
            rec[i].gen = gens;
            rec[i].nfe = Chromosome::hitnfe;
        }

        // Phase 1: Binary search if initial point is best
        while (rec[0].nfe < rec[1].nfe && ((rec[2].n - rec[0].n) * 20 > rec[1].n)) {
            rec[2] = rec[1];
            rec[1].n = (rec[0].n + rec[2].n) / 2;
            step_size /= 2;

            DSMGA2 ga(problemSize, rec[1].n, maxGenerations, maxEvaluations, fitnessFunc);
            int gens = ga.doIt(false);
            rec[1].gen = gens;
            rec[1].nfe = Chromosome::hitnfe;
        }

        // Phase 1: Expand search range if needed
        while ((rec[1].nfe >= rec[0].nfe) || (rec[1].nfe >= rec[2].nfe)) {
            int popu = rec[2].n + step_size;
            
            DSMGA2 ga(problemSize, popu, maxGenerations, maxEvaluations, fitnessFunc);
            int gens = ga.doIt(false);

            rec[0] = rec[1];
            rec[1] = rec[2];
            rec[2].n = popu;
            rec[2].gen = gens;
            rec[2].nfe = Chromosome::hitnfe;
        }

        // Phase 2: Fine-tuning with quartile searches
        while (((rec[2].n - rec[0].n) * 20 > rec[1].n) && 
               (rec[2].n > rec[1].n + 1) && 
               (rec[1].n > rec[0].n + 1)) {
            
            // Test quarter points
            Record q1, q3;
            q1.n = (rec[0].n + rec[1].n) / 2;
            q3.n = (rec[1].n + rec[2].n) / 2;

            // Evaluate q1
            DSMGA2 ga1(problemSize, q1.n, maxGenerations, maxEvaluations, fitnessFunc);
            q1.gen = ga1.doIt(false);
            q1.nfe = Chromosome::hitnfe;

            // Evaluate q3
            DSMGA2 ga3(problemSize, q3.n, maxGenerations, maxEvaluations, fitnessFunc);
            q3.gen = ga3.doIt(false);
            q3.nfe = Chromosome::hitnfe;

            // Update records based on best result
            if (rec[1].nfe < q1.nfe && rec[1].nfe < q3.nfe) {
                rec[0] = q1;
                rec[2] = q3;
            } else if (q1.nfe < rec[1].nfe && q1.nfe < q3.nfe) {
                rec[2] = rec[1];
                rec[1] = q1;
            } else {
                rec[0] = rec[1];
                rec[1] = q3;
            }
        }

        auto end_time = std::chrono::steady_clock::now();
        double duration = std::chrono::duration<double>(end_time - start_time).count();

        py::dict result;
        result["optimal_population"] = rec[1].n;
        result["generations"] = rec[1].gen;
        result["nfe"] = rec[1].nfe;
        result["time"] = duration;

        return result;
    }
};

std::vector<double> binary_to_real(const std::vector<int>& binary, int n_vars, double search_range) {
    int n_bits_per_var = binary.size() / n_vars;
    std::vector<double> real_values;
    real_values.reserve(n_vars);
    
    for (int i = 0; i < n_vars; i++) {
        int integer_value = 0;
        for (int j = 0; j < n_bits_per_var; j++) {
            integer_value = (integer_value << 1) | binary[i * n_bits_per_var + j];
        }
        int max_integer = (1 << n_bits_per_var) - 1;
        double real_value = -search_range + (2 * search_range * integer_value) / max_integer;
        real_values.push_back(real_value);
    }
    
    return real_values;
}

py::object optimize_dsmga2(const std::function<double(const std::vector<double>&)>& func,
                          const std::vector<std::pair<double, double>>& bounds,
                          py::kwargs kwargs) {
    // Parse kwargs with defaults matching scipy.optimize
    int popsize = kwargs.contains("popsize") ? 
        kwargs["popsize"].cast<int>() : 15 * bounds.size();
    int maxiter = kwargs.contains("maxiter") ? 
        kwargs["maxiter"].cast<int>() : 1000;
    bool disp = kwargs.contains("disp") ? 
        kwargs["disp"].cast<bool>() : false;
    
    // Verify bounds are uniform
    double search_range = bounds[0].second;
    for (const auto& bound : bounds) {
        if (bound.first != -search_range || bound.second != search_range) {
            throw std::runtime_error("DSMGA2 currently only supports symmetric bounds");
        }
    }
    
    int n_vars = bounds.size();
    int bits_per_var = 10;
    int total_bits = n_vars * bits_per_var;
    
    // Create wrapper for binary objective function
    auto binary_objective = [&](const std::vector<int>& x) {
        std::vector<double> real_x = binary_to_real(x, n_vars, search_range);
        return -func(real_x);  // Negative because DSMGA2 maximizes
    };
    
    // Run optimization
    auto start_time = std::chrono::steady_clock::now();
    
    // Create PyOptimizer instance and run optimization
    PyOptimizer optimizer(total_bits, popsize, maxiter);
    optimizer.set_objective_function(binary_objective);
    auto [solution, fitness] = optimizer.optimize();
    
    auto end_time = std::chrono::steady_clock::now();
    double duration = std::chrono::duration<double>(end_time - start_time).count();
    
    // Convert solution to real values
    std::vector<double> x = binary_to_real(solution, n_vars, search_range);
    
    // Create and return result dictionary matching scipy.optimize format
    py::dict result;
    result["x"] = x;
    result["fun"] = -fitness;  // Convert back to minimization
    result["success"] = true;
    result["message"] = "Optimization terminated successfully.";
    result["nfev"] = popsize * maxiter;  // Approximate number of function evaluations
    result["nit"] = maxiter;
    result["time"] = duration;
    
    return result;
}

py::object sweep_dsmga2(const std::function<double(const std::vector<double>&)>& func,
                       const std::vector<std::pair<double, double>>& bounds,
                       py::kwargs kwargs) {
    int min_pop = kwargs.contains("min_pop") ? kwargs["min_pop"].cast<int>() : 10;
    int max_pop = kwargs.contains("max_pop") ? kwargs["max_pop"].cast<int>() : 200;
    int step_size = kwargs.contains("step_size") ? kwargs["step_size"].cast<int>() : 30;
    int maxiter = kwargs.contains("maxiter") ? kwargs["maxiter"].cast<int>() : 1000;
    bool disp = kwargs.contains("disp") ? kwargs["disp"].cast<bool>() : false;

    // Get search range from bounds
    double search_range = bounds[0].second;
    int n_vars = bounds.size();
    int bits_per_var = 10;
    int total_bits = n_vars * bits_per_var;

    // Create optimizer with total bits as problem size
    PyOptimizer optimizer(total_bits, min_pop, maxiter);
    
    // Set objective function with binary to real conversion
    optimizer.set_objective_function([&](const std::vector<int>& binary) {
        std::vector<double> real_x = binary_to_real(binary, n_vars, search_range);
        return -func(real_x);  // Note: DSMGA2 maximizes, so we negate
    });

    // Run sweep
    py::dict result = optimizer.sweep(min_pop, max_pop, step_size);
    
    if (disp) {
        py::print("Sweep completed:");
        py::print("Optimal population size:", result["optimal_population"]);
        py::print("Generations:", result["generations"]);
        py::print("NFE:", result["nfe"]);
        py::print("Time:", result["time"]);
    }

    return result;
}

PYBIND11_MODULE(dsmga2, m) {
    m.doc() = "DSMGA-II optimization algorithm with scipy.optimize-like interface";

    py::class_<PyOptimizer>(m, "DSMGA2")
        .def(py::init<int, int, int, int, const std::string&>(),
             py::arg("problem_size"),
             py::arg("population_size") = 100,
             py::arg("max_generations") = 1000,
             py::arg("max_evaluations") = -1,
             py::arg("fitness_type") = "custom")
        .def("set_objective_function", &PyOptimizer::set_objective_function,
             "Set the custom objective function")
        .def("optimize", &PyOptimizer::optimize,
             "Run the optimization and return (best_solution, best_fitness)")
        .def("sweep", &PyOptimizer::sweep,
             py::arg("min_pop") = 10,
             py::arg("max_pop") = 200,
             py::arg("step_size") = 30,
             "Find optimal population size for the problem");

    m.def("dsmga2", &optimize_dsmga2,
          "Minimize a function using DSMGA2");
    
    m.def("sweep", &sweep_dsmga2,
          "Find optimal parameters for DSMGA2");
}