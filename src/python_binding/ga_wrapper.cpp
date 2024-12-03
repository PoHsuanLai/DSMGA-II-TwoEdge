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
        
        // Map string to FitnessType
        std::map<std::string, FitnessType> fitnessMap = {
            {"onemax", FITNESS_ONEMAX},
            {"mktrap", FITNESS_MKTRAP},
            {"ftrap", FITNESS_FTRAP},
            {"cyctrap", FITNESS_CYCTRAP},
            {"nk", FITNESS_NK},
            {"sat", FITNESS_SAT},
            {"custom", FITNESS_CUSTOM}
        };

        // Convert string to lowercase for case-insensitive comparison
        std::string type_lower = fitness_type;
        std::transform(type_lower.begin(), type_lower.end(), type_lower.begin(), ::tolower);

        auto it = fitnessMap.find(type_lower);
        if (it != fitnessMap.end()) {
            fitnessType = it->second;
            useCustomFunction = (fitnessType == FITNESS_CUSTOM);
        } else {
            throw std::invalid_argument("Invalid fitness type. Available types: onemax, mktrap, ftrap, cyctrap, nk, sat, custom");
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
        int generations = ga.doIt(false);

        // Get solution and fitness directly
        std::vector<int> solution = ga.getBest();
        double fitness = ga.getBestFitness();

        return {solution, fitness};
    }
};

class PySweep {
private:
    int problemSize;
    int numConvergence;
    FitnessType fitnessType;
    int problemNum;
    int neighborNum;
    int stepNum;

public:
    PySweep(int problem_size, 
            int num_convergence,
            const std::string& fitness_type,
            int problem_num = 0,
            int neighbor_num = 4,
            int step_num = 0) 
        : problemSize(problem_size)
        , numConvergence(num_convergence)
        , problemNum(problem_num)
        , neighborNum(neighbor_num)
        , stepNum(step_num) {
        
        // Map string to FitnessType (same as before)
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
        } else {
            throw std::invalid_argument("Invalid fitness type");
        }
    }

    std::tuple<int, double, double> run_sweep() {
        // Load necessary files based on fitness type
        if (fitnessType == FITNESS_NK) {
            char filename[200];
            sprintf(filename, "./NK_Instance/pnk%d_%d_%d_%d", 
                    problemSize, neighborNum, stepNum, problemNum);
            FILE *fp = fopen(filename, "r");
            if (!fp) throw std::runtime_error("Failed to open NK instance file");
            loadNKWAProblem(fp, &nkwa);
            fclose(fp);
        } else if (fitnessType == FITNESS_SAT) {
            char filename[200];
            sprintf(filename, "./SAT/uf%d/uf%d-0%d.cnf",
                    problemSize, problemSize, problemNum);
            loadSAT(filename, &mySAT);
        }

        // Run sweep algorithm
        Statistics st;
        Statistics stGen, stLS, stNFE;
        int bestPopulation;
        double bestGeneration;
        double bestNFE;

        // Call the sweep algorithm (modified version of main() from sweep.cpp)
        // ... (implement the sweep logic here)

        // Clean up
        if (fitnessType == FITNESS_NK) {
            freeNKWAProblem(&nkwa);
        }

        return std::make_tuple(bestPopulation, bestGeneration, bestNFE);
    }
};

PYBIND11_MODULE(dsmga2, m) {
    m.doc() = "DSMGA-II optimization algorithm with sweep functionality";

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
             "Run the optimization and return (best_solution, best_fitness)");

    py::class_<PySweep>(m, "Sweep")
        .def(py::init<int, int, const std::string&, int, int, int>(),
             py::arg("problem_size"),
             py::arg("num_convergence"),
             py::arg("fitness_type"),
             py::arg("problem_num") = 0,
             py::arg("neighbor_num") = 4,
             py::arg("step_num") = 0)
        .def("run_sweep", &PySweep::run_sweep,
             "Run sweep algorithm to find optimal parameters");
} 