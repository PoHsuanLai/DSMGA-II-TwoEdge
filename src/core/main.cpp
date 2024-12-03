/***************************************************************************
 *   Copyright (C) 2015 Tian-Li Yu and Shih-Huan Hsu                       *
 *   tianliyu@ntu.edu.tw                                                   *
 ***************************************************************************/


#include <cmath>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "statistics.h"
#include "dsmga2.h"
#include "global.h"
#include "chromosome.h"
#include "fitness_functions.h"

using namespace std;

int main(int argc, char *argv[]) {
    if (argc != 9) {
        printf("Usage: DSMGA2 <problemSize> <initialPopulation> <fitnessType> <maxGenerations> <maxEvaluations> <repeats> <display> <randomSeed>\n");
        printf("Fitness Types:\n");
        printf("     ONEMAX     : 0\n");
        printf("     MK TRAP    : 1\n");
        printf("     FTRAP      : 2\n");
        printf("     CYCLIC TRAP: 3\n");
        printf("     NK         : 4\n");
        printf("     SPIN GLASS : 5\n");
        printf("     SAT        : 6\n");
        printf("     CUSTOM     : 7\n");
        return -1;
    }

    int problemSize = atoi(argv[1]);
    int initialPopulation = atoi(argv[2]);
    int fitnessType = atoi(argv[3]);
    int maxGenerations = atoi(argv[4]);
    int maxEvaluations = atoi(argv[5]);
    int repeats = atoi(argv[6]);
    int display = atoi(argv[7]);
    int randomSeed = atoi(argv[8]);

    if (fitnessType == FITNESS_NK) {
        char filename[200];
        sprintf(filename, "./NK_Instance/pnk%d_%d_%d_%d", problemSize, 4, 5, 1);
        if (SHOW_BISECTION) printf("Loading: %s\n", filename);
        FILE *fp = fopen(filename, "r");
        loadNKWAProblem(fp, &nkwa);
        fclose(fp);
    }

    if (fitnessType == FITNESS_SPINGLASS) {
        char filename[200];
        sprintf(filename, "./SPIN/%d/%d_%d", problemSize, problemSize, 1);
        if (SHOW_BISECTION) printf("Loading: %s\n", filename);
        loadSPIN(filename, &mySpinGlassParams);
    }

    if (fitnessType == FITNESS_SAT) {
        char filename[200];
        sprintf(filename, "./SAT/uf%d/uf%d-0%d.cnf", problemSize, problemSize, 1);
        if (SHOW_BISECTION) printf("Loading: %s\n", filename);
        loadSAT(filename, &mySAT);
    }

    if (randomSeed != -1)
        myRand.seed((unsigned long)randomSeed);

    Statistics stGen, stFE, stLSFE;
    int failCount = 0;

    // Get fitness function
    auto fitnessFunction = getFitnessFunction(static_cast<FitnessType>(fitnessType));
    if (!fitnessFunction) {
        printf("Invalid fitness type\n");
        return -1;
    }
    
    DSMGA2 ga(problemSize, initialPopulation, maxGenerations, maxEvaluations, fitnessFunction);

    int usedGenerations = (display == 1) ? ga.doIt(true) : ga.doIt(false);

    if (!ga.foundOptima()) {
        failCount++;
        printf("-");
    } else {
        stFE.record(Chromosome::hitnfe);
        stLSFE.record(Chromosome::lsnfe);
        stGen.record(usedGenerations);
        printf("+");
    }

    fflush(NULL);

    cout << endl;
    printf("Average Generations: %f, Average NFE: %f, Average LSFE: %f, Failures: %d\n", stGen.getMean(), stFE.getMean(), stLSFE.getMean(), failCount);

    if (fitnessType == FITNESS_NK) freeNKWAProblem(&nkwa);

    return EXIT_SUCCESS;
}
