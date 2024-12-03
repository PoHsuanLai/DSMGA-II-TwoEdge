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

### Using Predefined Fitness Functions
```python
import dsmga2

# Create optimizer with a predefined fitness function
optimizer = dsmga2.DSMGA2(
    problem_size=100,
    population_size=100,
    max_generations=1000,
    fitness_type="onemax"  # Use predefined OneMax function
)

# Run optimization
solution, fitness = optimizer.optimize()
print(f"Solution: {solution}")
print(f"Fitness: {fitness}")
```

Available predefined fitness functions:
- `"onemax"`: Counts the number of ones in the bit string
- `"mktrap"`: MK Trap function
- `"ftrap"`: Folded Trap function
- `"cyctrap"`: Cyclic Trap function
- `"nk"`: NK Landscapes
- `"sat"`: Boolean Satisfiability Problem
- `"custom"`: For user-defined objective functions

### Using Custom Objective Function
```python
import dsmga2

# Create optimizer
optimizer = dsmga2.DSMGA2(
    problem_size=100,
    fitness_type="custom"
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