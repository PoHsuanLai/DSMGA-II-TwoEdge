"""
DSMGA2 Tutorial and Examples
===========================

This tutorial demonstrates how to use the DSMGA2 (Dependency Structure Matrix Genetic Algorithm II)
optimizer with:
1. All predefined fitness functions (OneMax, MKTrap, FTrap, CycTrap, NK, SAT)
2. A challenging benchmark problem (Rastrigin function adapted for binary optimization)
3. Common error cases and how to handle them
4. Parameter tuning examples
"""

try:
    from dsmga2 import DSMGA2
    import numpy as np
except Exception as e:
    print(f"Error occurred: {str(e)}")

# =============================================================================
# Example 1: All Predefined Fitness Functions
# =============================================================================
print("\n1. Demonstrating All Predefined Fitness Functions")
print("=" * 50)

# Test configuration for each function
test_configs = [
    {
        "name": "OneMax",
        "type": "onemax",
        "size": 100,
        "description": "Counts the number of 1s in a binary string"
    },
    {
        "name": "MK-Trap",
        "type": "mktrap",
        "size": 100,
        "description": "Multiple k-trap function with overlapping building blocks"
    },
    {
        "name": "F-Trap",
        "type": "ftrap",
        "size": 100,
        "description": "Fixed trap function with non-overlapping building blocks"
    },
    {
        "name": "Cyclic-Trap",
        "type": "cyctrap",
        "size": 100,
        "description": "Cyclic trap function with circular dependencies"
    },
    {
        "name": "NK-Landscape",
        "type": "nk",
        "size": 100,
        "description": "NK-landscape problem with tunable ruggedness"
    },
    {
        "name": "SAT",
        "type": "sat",
        "size": 100,
        "description": "Boolean satisfiability problem"
    }
]

for config in test_configs:
    print(f"\nTesting {config['name']}")
    print("-" * 30)
    print(f"Description: {config['description']}")
    
    optimizer = DSMGA2(
        problem_size=config['size'],
        population_size=50,
        max_generations=1000,
        fitness_type=config['type']
    )
    
    solution, fitness = optimizer.optimize()
    print(f"Results:")
    print(f"- Final fitness: {fitness}")
    print(f"- Number of 1s: {sum(solution)}")
    print(f"- Solution length: {len(solution)}")

# =============================================================================
# Example 2: Challenging Benchmark Problem (Binary Rastrigin)
# =============================================================================
print("\n2. Binary Rastrigin Function Optimization")
print("=" * 50)
print("The Rastrigin function is a highly multimodal problem commonly used to")
print("test optimization algorithms. We'll adapt it for binary optimization.")

def binary_rastrigin(x, n_bits_per_var=10, search_range=5.12):
    """
    Binary-encoded Rastrigin function.
    
    Args:
        x (list): Binary string
        n_bits_per_var (int): Number of bits per variable
        search_range (float): Search range [-search_range, search_range]
        
    Returns:
        float: Fitness value (negated for maximization)
    """
    # Convert binary string to real values
    n_vars = len(x) // n_bits_per_var
    real_values = []
    
    for i in range(n_vars):
        binary_segment = x[i * n_bits_per_var : (i + 1) * n_bits_per_var]
        integer_value = sum(bit << idx for idx, bit in enumerate(reversed(binary_segment)))
        max_integer = (1 << n_bits_per_var) - 1
        real_value = -search_range + (2 * search_range * integer_value) / max_integer
        real_values.append(real_value)
    
    # Calculate Rastrigin function
    result = 10 * len(real_values)
    for x_i in real_values:
        result += x_i**2 - 10 * np.cos(2 * np.pi * x_i)
    
    # Return negated value since DSMGA2 maximizes
    return -result

# Initialize optimizer for Rastrigin function
n_variables = 5  # Number of variables in Rastrigin function
bits_per_var = 10  # Bits per variable
total_bits = n_variables * bits_per_var

optimizer_rastrigin = DSMGA2(
    problem_size=total_bits,
    population_size=100,
    max_generations=1000,
    max_evaluations=-1,
    fitness_type="custom"
)

optimizer_rastrigin.set_objective_function(binary_rastrigin)

print("\nOptimizing Rastrigin function...")
solution_rastrigin, fitness_rastrigin = optimizer_rastrigin.optimize()

# Convert solution to real values for display
real_solution = []
for i in range(n_variables):
    binary_segment = solution_rastrigin[i * bits_per_var : (i + 1) * bits_per_var]
    integer_value = sum(bit << idx for idx, bit in enumerate(reversed(binary_segment)))
    max_integer = (1 << bits_per_var) - 1
    real_value = -5.12 + (2 * 5.12 * integer_value) / max_integer
    real_solution.append(real_value)

print(f"Rastrigin Results:")
print(f"- Final fitness: {fitness_rastrigin}")
print(f"- Real values: {real_solution}")
print(f"- Global optimum is at [0, 0, 0, 0, 0] with fitness 0")

# =============================================================================
# Example 3: Common Error Cases
# =============================================================================
print("\n3. Demonstrating Common Error Cases")
print("=" * 50)

# Case 1: Trying to optimize with custom fitness type but without setting the function
print("\nCase 1: Missing Custom Objective Function")
optimizer3 = DSMGA2(problem_size=100, fitness_type="custom")
try:
    solution3, fitness3 = optimizer3.optimize()
except RuntimeError as e:
    print(f"Expected error occurred: {e}")

# Case 2: Trying to set custom function for predefined fitness type
print("\nCase 2: Setting Custom Function with Predefined Fitness Type")
optimizer4 = DSMGA2(problem_size=100, fitness_type="onemax")
try:
    optimizer4.set_objective_function(binary_rastrigin)
except RuntimeError as e:
    print(f"Expected error occurred: {e}")

# =============================================================================
# Example 4: Parameter Tuning Example
# =============================================================================
print("\n4. Parameter Tuning Example")
print("=" * 50)
print("Demonstrating how different population sizes affect convergence")

population_sizes = [20, 50, 100]
for pop_size in population_sizes:
    optimizer = DSMGA2(
        problem_size=100,
        population_size=pop_size,
        max_generations=500,
        fitness_type="onemax"
    )
    solution, fitness = optimizer.optimize()
    print(f"\nPopulation size {pop_size}:")
    print(f"- Final fitness: {fitness}")
    print(f"- Solution quality (% of optimal): {(fitness/100)*100:.2f}%")

print("\nTutorial Complete!")
print("=" * 50)
print("Key Takeaways:")
print("1. DSMGA2 supports multiple predefined fitness functions")
print("2. Can handle complex optimization problems through binary encoding")
print("3. Custom objective functions must be properly defined and set")
print("4. Population size affects solution quality and convergence speed")