"""
Optimization Methods Comparison
-----------------------------
Comparing DSMGA2 with common optimization methods from SciPy
on standard benchmark functions and predefined DSMGA2 fitness functions.
"""

import numpy as np
from scipy.optimize import differential_evolution, dual_annealing, basinhopping
from dsmga2 import DSMGA2
import time
from tabulate import tabulate
import matplotlib.pyplot as plt

class BenchmarkFunctions:
    @staticmethod
    def rastrigin(x):
        """Rastrigin function (global minimum at x=0)"""
        return 10 * len(x) + sum(xi**2 - 10 * np.cos(2 * np.pi * xi) for xi in x)
    
    @staticmethod
    def rosenbrock(x):
        """Rosenbrock function (global minimum at x=1)"""
        return sum(100 * (x[i+1] - x[i]**2)**2 + (1 - x[i])**2 for i in range(len(x)-1))
    
    @staticmethod
    def ackley(x):
        """Ackley function (global minimum at x=0)"""
        n = len(x)
        sum_sq = np.sum(np.array(x)**2)
        sum_cos = np.sum(np.cos(2*np.pi*np.array(x)))
        return -20*np.exp(-0.2*np.sqrt(sum_sq/n)) - np.exp(sum_cos/n) + 20 + np.e

def binary_to_real(binary, n_vars, search_range=5.12):
    """Convert binary solution to real values"""
    n_bits_per_var = len(binary) // n_vars
    real_values = []
    
    for i in range(n_vars):
        binary_segment = binary[i * n_bits_per_var : (i + 1) * n_bits_per_var]
        integer_value = sum(bit << idx for idx, bit in enumerate(reversed(binary_segment)))
        max_integer = (1 << n_bits_per_var) - 1
        real_value = -search_range + (2 * search_range * integer_value) / max_integer
        real_values.append(real_value)
    
    return real_values

def run_comparison(func, n_vars=5, n_trials=10):
    """Run comparison between different optimization methods"""
    results = {
        'DSMGA2': {'best': [], 'time': [], 'fevals': []},
        'DE': {'best': [], 'time': [], 'fevals': []},
        'DA': {'best': [], 'time': [], 'fevals': []},
        'BH': {'best': [], 'time': [], 'fevals': []}
    }
    
    bounds = [(-5.12, 5.12)] * n_vars
    
    # Parameters for DSMGA2
    bits_per_var = 10
    total_bits = n_vars * bits_per_var
    
    for trial in range(n_trials):
        print(f"Trial {trial + 1}/{n_trials}")
        
        # DSMGA2
        def binary_objective(x):
            real_x = binary_to_real(x, n_vars)
            return -func(real_x)  # Negative because DSMGA2 maximizes
        
        start_time = time.time()
        optimizer = DSMGA2(
            problem_size=total_bits,
            population_size=100,
            max_generations=1000,
            fitness_type="custom"
        )
        optimizer.set_objective_function(binary_objective)
        solution, fitness = optimizer.optimize()
        real_solution = binary_to_real(solution, n_vars)
        results['DSMGA2']['best'].append(-fitness)  # Convert back to minimization
        results['DSMGA2']['time'].append(time.time() - start_time)
        
        # Differential Evolution
        start_time = time.time()
        result = differential_evolution(func, bounds)
        results['DE']['best'].append(result.fun)
        results['DE']['time'].append(time.time() - start_time)
        results['DE']['fevals'].append(result.nfev)
        
        # Dual Annealing
        start_time = time.time()
        result = dual_annealing(func, bounds)
        results['DA']['best'].append(result.fun)
        results['DA']['time'].append(time.time() - start_time)
        results['DA']['fevals'].append(result.nfev)
        
        # Basin Hopping
        start_time = time.time()
        result = basinhopping(func, x0=np.zeros(n_vars), minimizer_kwargs={'bounds': bounds})
        results['BH']['best'].append(result.fun)
        results['BH']['time'].append(time.time() - start_time)
        
    return results

def print_comparison_table(results):
    """Print comparison results in a nice table format"""
    table_data = []
    headers = ['Method', 'Best', 'Mean', 'Std', 'Avg Time (s)', 'Success Rate']
    
    for method in results:
        best_values = results[method]['best']
        times = results[method]['time']
        
        # Calculate statistics
        best = min(best_values)
        mean = np.mean(best_values)
        std = np.std(best_values)
        avg_time = np.mean(times)
        success_rate = sum(1 for x in best_values if x < 1e-4) / len(best_values)
        
        table_data.append([
            method,
            f"{best:.2e}",
            f"{mean:.2e}",
            f"{std:.2e}",
            f"{avg_time:.2f}",
            f"{success_rate*100:.1f}%"
        ])
    
    print(tabulate(table_data, headers=headers, tablefmt='grid'))

def plot_convergence(results):
    """Plot convergence comparison"""
    plt.figure(figsize=(10, 6))
    for method in results:
        plt.plot(sorted(results[method]['best']), label=method)
    plt.yscale('log')
    plt.xlabel('Sorted Trial Index')
    plt.ylabel('Best Function Value (log scale)')
    plt.title('Comparison of Optimization Methods')
    plt.legend()
    plt.grid(True)
    plt.savefig('optimization_comparison.png')
    plt.close()

def test_predefined_functions(problem_size=1000, n_trials=10):
    """Test DSMGA2's predefined fitness functions with increased difficulty"""
    fitness_types = ["onemax", "mktrap", "ftrap", "cyctrap", "nk", "sat"]
    results = {
        'DSMGA2': {ft: {'best': [], 'time': []} for ft in fitness_types}
    }
    
    for fitness_type in fitness_types:
        print(f"\nTesting {fitness_type.upper()} Function")
        print("=" * 50)
        
        for trial in range(n_trials):
            print(f"Trial {trial + 1}/{n_trials}")
            
            # DSMGA2
            start_time = time.time()
            optimizer = DSMGA2(
                problem_size=problem_size,
                population_size=200,  # Increased population size
                max_generations=2000,  # Increased generations
                fitness_type=fitness_type
            )
            solution, fitness = optimizer.optimize()
            results['DSMGA2'][fitness_type]['best'].append(fitness)
            results['DSMGA2'][fitness_type]['time'].append(time.time() - start_time)
            
            print(f"Trial {trial + 1} completed - Fitness: {fitness:.4f}, Time: {time.time() - start_time:.2f}s")
        
        # Print results for this fitness function
        print(f"\nResults for {fitness_type.upper()}:")
        print_comparison_table_predefined(results, fitness_type)
        plot_convergence_predefined(results, fitness_type)
    
    return results

def print_comparison_table_predefined(results, fitness_type):
    """Print comparison results for predefined functions"""
    table_data = []
    headers = ['Method', 'Best', 'Mean', 'Std', 'Avg Time (s)']
    
    for method in results:
        best_values = results[method][fitness_type]['best']
        times = results[method][fitness_type]['time']
        
        best = max(best_values)  # max because these are maximization problems
        mean = np.mean(best_values)
        std = np.std(best_values)
        avg_time = np.mean(times)
        
        table_data.append([
            method,
            f"{best:.2f}",
            f"{mean:.2f}",
            f"{std:.2f}",
            f"{avg_time:.2f}"
        ])
    
    print(tabulate(table_data, headers=headers, tablefmt='grid'))

def plot_convergence_predefined(results, fitness_type):
    """Plot convergence comparison for predefined functions"""
    plt.figure(figsize=(10, 6))
    for method in results:
        plt.plot(sorted(results[method][fitness_type]['best']), label=method)
    plt.xlabel('Sorted Trial Index')
    plt.ylabel('Fitness Value')
    plt.title(f'Performance on {fitness_type.upper()}')
    plt.legend()
    plt.grid(True)
    plt.savefig(f'comparison_{fitness_type}.png')
    plt.close()

if __name__ == "__main__":
    # Test predefined fitness functions with increased difficulty
    print("\nTesting Predefined Fitness Functions")
    print("=" * 50)
    predefined_results = test_predefined_functions(problem_size=1000)
    
    # Test continuous optimization benchmarks
    print("\nTesting Continuous Optimization Benchmarks")
    print("=" * 50)
    
    print("\nTesting Rastrigin Function")
    print("=" * 50)
    results_rastrigin = run_comparison(BenchmarkFunctions.rastrigin)
    print_comparison_table(results_rastrigin)
    plot_convergence(results_rastrigin)
    
    print("\nTesting Rosenbrock Function")
    print("=" * 50)
    results_rosenbrock = run_comparison(BenchmarkFunctions.rosenbrock)
    print_comparison_table(results_rosenbrock)
    plot_convergence(results_rosenbrock)
    
    print("\nTesting Ackley Function")
    print("=" * 50)
    results_ackley = run_comparison(BenchmarkFunctions.ackley)
    print_comparison_table(results_ackley)
    plot_convergence(results_ackley)
