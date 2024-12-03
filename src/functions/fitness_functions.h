#ifndef _FITNESS_FUNCTIONS_H_
#define _FITNESS_FUNCTIONS_H_

#include "chromosome.h"
#include "spin.h"
#include "nk-wa.h"
#include "sat.h"
#include <functional>

#define TRAP_K 5

// Define fitness function types
enum FitnessType {
    FITNESS_ONEMAX = 0,
    FITNESS_MKTRAP = 1,
    FITNESS_FTRAP = 2,
    FITNESS_CYCTRAP = 3,
    FITNESS_NK = 4,
    FITNESS_SPINGLASS = 5,
    FITNESS_SAT = 6,
    FITNESS_CUSTOM = 7
};

// Helper function
double trap(int unitary, double fHigh, double fLow, int trapK);

// Declare fitness functions
double oneMaxFitness(const Chromosome& ch);
double mkTrapFitness(const Chromosome& ch);
double fTrapFitness(const Chromosome& ch);
double cycTrapFitness(const Chromosome& ch);
double nkFitness(const Chromosome& ch);
double spinGlassFitness(const Chromosome& ch);
double satFitness(const Chromosome& ch);

// Function to get appropriate fitness function based on type
std::function<double(const Chromosome&)> getFitnessFunction(FitnessType type);

#endif 