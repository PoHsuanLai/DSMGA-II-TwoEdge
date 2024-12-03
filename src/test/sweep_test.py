"""
DSMGA-II Parameter Sweep Test
----------------------------
Using the sweep algorithm to find optimal parameters for different problem types.
"""

from dsmga2 import Sweep
import time
from tabulate import tabulate
import matplotlib.pyplot as plt

def test_with_sweep(problem_size=100, num_convergence=10):
    """Test different fitness functions using the sweep algorithm"""
    
    fitness_types = ["onemax", "mktrap", "ftrap", "cyctrap", "nk", "sat"]
    results = {}
    
    for fitness_type in fitness_types:
        print(f"\nTesting {fitness_type.upper()} Function")
        print("=" * 50)
        
        try:
            # Create sweep instance
            sweep = Sweep(
                problem_size=problem_size,
                num_convergence=num_convergence,
                fitness_type=fitness_type
            )
            
            # Run sweep
            start_time = time.time()
            population, generations, nfe = sweep.run_sweep()
            elapsed_time = time.time() - start_time
            
            results[fitness_type] = {
                'population': population,
                'generations': generations,
                'nfe': nfe,
                'time': elapsed_time
            }
            
            print(f"\nResults for {fitness_type.upper()}:")
            print(f"Optimal Population Size: {population}")
            print(f"Average Generations: {generations:.2f}")
            print(f"Average NFE: {nfe:.2f}")
            print(f"Time taken: {elapsed_time:.2f}s")
            
        except Exception as e:
            print(f"Error testing {fitness_type}: {str(e)}")
    
    return results

def print_results_table(results):
    """Print results in a nice table format"""
    headers = ['Fitness Type', 'Population', 'Generations', 'NFE', 'Time (s)']
    table_data = []
    
    for ft in results:
        table_data.append([
            ft.upper(),
            results[ft]['population'],
            f"{results[ft]['generations']:.2f}",
            f"{results[ft]['nfe']:.2f}",
            f"{results[ft]['time']:.2f}"
        ])
    
    print("\nOverall Results:")
    print(tabulate(table_data, headers=headers, tablefmt='grid'))

if __name__ == "__main__":
    # Test with different problem sizes
    problem_sizes = [100, 200, 500, 1000]
    all_results = {}
    
    for size in problem_sizes:
        print(f"\nTesting with problem size {size}")
        print("=" * 50)
        
        results = test_with_sweep(problem_size=size, num_convergence=10)
        all_results[size] = results
        print_results_table(results)
    
    # Plot results
    plt.figure(figsize=(12, 6))
    for ft in all_results[problem_sizes[0]].keys():
        sizes = problem_sizes
        populations = [all_results[size][ft]['population'] for size in sizes]
        plt.plot(sizes, populations, marker='o', label=ft.upper())
    
    plt.xlabel('Problem Size')
    plt.ylabel('Optimal Population Size')
    plt.title('Population Size Scaling with Problem Size')
    plt.legend()
    plt.grid(True)
    plt.savefig('population_scaling.png')
    plt.close() 