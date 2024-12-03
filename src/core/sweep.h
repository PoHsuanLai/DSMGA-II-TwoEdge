#ifndef _SWEEP_H_
#define _SWEEP_H_

#include "statistics.h"
#include "dsmga2.h"
#include "global.h"
#include "fitness_functions.h"

struct Record {
    int n;
    double nfe;
    double gen;
};

// Main sweep function that can be called from other files
std::tuple<int, double, double> runSweep(
    int problemSize,
    int numConvergence,
    FitnessType fitnessType,
    int problemNum = 0,
    int neighborNum = 4,
    int stepNum = 0
);

#endif 