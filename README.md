# DSMGA-II-TwoEdge

## Overview
This is a C++ implementation of the Dependency Structure Matrix Genetic Algorithm II (DSMGA-II) featuring a two-edge graphical linkage model. This enhanced version builds upon the original DSMGA-II by incorporating a more sophisticated linkage detection mechanism.

## Description
DSMGA-II is an advanced evolutionary algorithm that excels at solving complex optimization problems by effectively identifying and utilizing problem structure. The two-edge graphical linkage model extends the original algorithm's capabilities by allowing for more nuanced relationship detection between problem variables.

## Key Features
- Advanced linkage learning through two-edge graphical model
- Efficient optimization for complex problems
- Improved scalability compared to traditional genetic algorithms
- Support for various benchmark problems
- Python bindings for easy integration
- SciPy-like interface for continuous optimization problems

## Installation
```bash
# Clone the repository
git clone https://github.com/PoHsuanLai/DSMGA-II-TwoEdge.git

# Build the project
cd DSMGA-II-TwoEdge
mkdir build && cd build
cmake ..
make

# Install Python package (optional)
pip install -e .
```

## Usage

There are two ways to use this library:

### 1. Class-based Interface (For Predefined Fitness Functions)
Use this approach when working with predefined binary optimization problems:

```python
from dsmga2 import DSMGA2

# Create optimizer with minimal parameters
optimizer = DSMGA2(
    problem_size=100,  # Required
    fitness_type="onemax"  # Optional, defaults to "custom"
    # Optional parameters with defaults:
    # population_size=100
    # max_generations=1000
    # max_evaluations=-1
)

# Run optimization
solution, fitness = optimizer.optimize()

# Find optimal population size (all parameters optional)
result = optimizer.sweep(
    # min_pop=10
    # max_pop=200
    # step_size=30
)
print(f"Optimal population size: {result['optimal_population']}")
print(f"Generations needed: {result['generations']}")
print(f"Number of fitness evaluations: {result['nfe']}")
print(f"Time taken: {result['time']}")
```

Available predefined fitness functions:
- `"onemax"`: Counts the number of ones in the bit string
- `"mktrap"`: MK Trap function
- `"ftrap"`: Folded Trap function
- `"cyctrap"`: Cyclic Trap function
- `"nk"`: NK Landscapes
- `"sat"`: Boolean Satisfiability Problem
- `"custom"`: For user-defined objective functions

### 2. Standalone Functions (For Continuous Optimization)
Use this approach when working with continuous optimization problems:

```python
from dsmga2 import dsmga2, sweep
import numpy as np

# Define objective function
def rosenbrock(x):
    return sum(100.0 * (x[1:] - x[:-1]**2.0)**2.0 + (1 - x[:-1])**2.0)

# Define bounds for each variable
bounds = [(-5.12, 5.12)] * 10

# Run optimization (all parameters optional except function and bounds)
result = dsmga2(rosenbrock, bounds, 
                # popsize=15 * len(bounds)  # Default: 15 times problem dimension
                # maxiter=1000
                # disp=False
)

print(f"Solution: {result['x']}")
print(f"Objective value: {result['fun']}")

# Find optimal parameters (all parameters optional except function and bounds)
sweep_result = sweep(rosenbrock, bounds,
                    # min_pop=10
                    # max_pop=200
                    # step_size=30
                    # maxiter=1000
                    # disp=False
)
```

### Using Custom Binary Objective Function
When using the class-based interface with a custom binary objective function:

```python
from dsmga2 import DSMGA2

# Create optimizer (only problem_size required)
optimizer = DSMGA2(
    problem_size=100,
    # fitness_type="custom"  # Default
    # population_size=100    # Default
    # max_generations=1000   # Default
    # max_evaluations=-1     # Default
)

# Set custom objective function
def objective_function(x):
    return sum(x)  # Example: OneMax problem
optimizer.set_objective_function(objective_function)

# Run optimization
solution, fitness = optimizer.optimize()
```

## Academic Usage and Citation
This implementation is freely available for academic purposes. You may use, modify, or distribute the code with appropriate acknowledgment of the source. 

If you use this implementation in your research, please cite the following papers:

1. For the DSMGA-II algorithm:
```
S.-H. Hsu and T.-L. Yu, "Optimization by pairwise linkage detection, incremental linkage set, 
and restricted/back mixing: DSMGA-II," Genetic and Evolutionary Computation Conference (GECCO 2015).
```

2. For the two-edge graphical linkage model:
```
P.-L. Chen, C.-J. Peng and T.-L. Yu, "DSMGA-II with two-edge graphical linkage model," 
Genetic and Evolutionary Computation Conference (GECCO 2017).
```

## Original Implementation
The original code is also available at: https://github.com/tianliyu/DSMGA-II-TwoEdge

## License
This project is available for academic use. Please ensure appropriate citation when using this code in your research.

## Contributing
Contributions are welcome! Please feel free to submit pull requests or open issues for any bugs or improvements.

## Contact
For questions or support, please open an issue in the GitHub repository.