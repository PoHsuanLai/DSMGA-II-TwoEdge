/***************************************************************************
 *   Copyright (C) 2015 Tian-Li Yu and Shih-Huan Hsu                       *
 *   tianliyu@ntu.edu.tw                                                   *
 ***************************************************************************/

#include <cstdlib>
#include <cmath>
#include <iostream>
#include <fstream>

#include "statistics.h"
#include "dsmga2.h"
#include "global.h"
#include "fitness_functions.h"
#define MAX_GEN 200

int step = 30;

using namespace std;

struct Record {
    int n;
    double nfe;
    double gen;
};

int main(int argc, char *argv[]) {
    if (argc != 4 && argc != 5 && argc != 6 && argc != 7) {
        printf("Usage: sweep <problemSize> <numConvergence> <fitnessType>\n");
        printf("   or: sweep <problemSize> <numConvergence> 4 [stepSize] [nkProblemNum]\n");
        printf("   or: sweep <problemSize> <numConvergence> 5 [spinProblemNum]\n");
        printf("   or: sweep <problemSize> <numConvergence> 6 [satProblemNum]\n");
        printf("   or: sweep <problemSize> <numConvergence> 7 [customProblemNum]\n");
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
    int numConvergence = atoi(argv[2]);
    int fitnessType = atoi(argv[3]);

    int problemNum = 0;
    int neighborNum = 0;
    int stepNum = 0;


    if (fitnessType == 4) {
        neighborNum = 4;
        stepNum = atoi (argv[4]);
        problemNum = atoi (argv[5]);
    }

    if (fitnessType == 5 || fitnessType == 6) {
        problemNum = atoi (argv[4]);
    }


    int nInitial = 10;


    // for debug
    // myRand.seed(123);


    Statistics st;

    Statistics stGen, stLS, stNFE;


    if (fitnessType == 5) {
	char filename[200];
        sprintf(filename, "./SPIN/%d/%d_%d",problemSize, problemSize, problemNum);
        if (SHOW_BISECTION) printf("Loading: %s\n", filename);
        loadSPIN(filename, &mySpinGlassParams);
    }

    if (fitnessType == 4) {
        char filename[200];
        sprintf(filename, "./NK_Instance/pnk%d_%d_%d_%d", problemSize, neighborNum, stepNum, problemNum);
        if (SHOW_BISECTION) printf("Loading: %s\n", filename);
        FILE *fp = fopen(filename, "r");
        loadNKWAProblem(fp, &nkwa);
        fclose(fp);
    }

    if (fitnessType == 6) {
        char filename[200];
        sprintf(filename, "./SAT/uf%d/uf%d-0%d.cnf",problemSize,problemSize,problemNum);
        if (SHOW_BISECTION) printf("Loading: %s\n", filename);
        loadSAT(filename, &mySAT);
    }


    bool foundOptima;
    Record rec[3];
    rec[0].n = nInitial;
    rec[1].n = nInitial+step;
    rec[2].n = nInitial+step+step;

    int popu;
    Record q1, q3;

    if (SHOW_BISECTION) printf("Bisection phase 1\n");

    for (int i=0; i<3; ++i) {
        popu = rec[i].n;

        if (SHOW_BISECTION) printf("[%d]: ", popu);

        foundOptima = true;

        stGen.reset();
        stNFE.reset();
        stLS.reset();

        auto fitnessFunction = getFitnessFunction(static_cast<FitnessType>(fitnessType));
        DSMGA2 ga(problemSize, popu, MAX_GEN, -1, fitnessFunction);
        ga.doIt(false);

        stGen.record(ga.getGeneration());
        stNFE.record(Chromosome::hitnfe);
        stLS.record(Chromosome::lsnfe);


        if (!ga.foundOptima()) {

            foundOptima = false;

            if (SHOW_BISECTION) {
                printf("-");
                fflush(NULL);
            }
            break;
        }

        if (SHOW_BISECTION) {
            printf("+");
            fflush(NULL);
        }


        rec[i].gen = stGen.getMean();

        if (!foundOptima)
            rec[i].nfe = INF;
        else
            rec[i].nfe = stNFE.getMean();

        if (SHOW_BISECTION) printf(" : %f \n", rec[i].nfe);

    }

    while (rec[0].nfe < rec[1].nfe  && ((rec[2].n-rec[0].n)*20 > rec[1].n)) {

        rec[2] = rec[1];
        rec[1].n = (rec[0].n + rec[2].n) / 2;
        step /= 2;
        popu = rec[1].n;

        if (SHOW_BISECTION) printf("[%d]: ", popu);

        foundOptima = true;

        stGen.reset();
        stNFE.reset();
        stLS.reset();

        auto fitnessFunction = getFitnessFunction(static_cast<FitnessType>(fitnessType));
        DSMGA2 ga(problemSize, popu, MAX_GEN, -1, fitnessFunction);
        ga.doIt(false);

        stGen.record(ga.getGeneration());
        stNFE.record(Chromosome::hitnfe);
        stLS.record(Chromosome::lsnfe);


        if (!ga.foundOptima()) {

            foundOptima = false;

            if (SHOW_BISECTION) {
                printf("-");
                fflush(NULL);
            }
            break;
        }

        if (SHOW_BISECTION) {
            printf("+");
            fflush(NULL);
        }


        rec[1].gen = stGen.getMean();

        if (!foundOptima)
            rec[1].nfe = INF;
        else
            rec[1].nfe = stNFE.getMean();

        if (SHOW_BISECTION) printf(" : %f \n", rec[1].nfe);

    }


    while ( (rec[1].nfe >= rec[0].nfe) || (rec[1].nfe >= rec[2].nfe)) {

        popu = rec[2].n + step;

        if (SHOW_BISECTION) printf("[%d]: ", popu);

        foundOptima = true;

        stGen.reset();
        stNFE.reset();
        stLS.reset();

        auto fitnessFunction = getFitnessFunction(static_cast<FitnessType>(fitnessType));
        DSMGA2 ga(problemSize, popu, MAX_GEN, -1, fitnessFunction);
        ga.doIt(false);

        stGen.record(ga.getGeneration());
        stNFE.record(Chromosome::hitnfe);
        stLS.record(Chromosome::lsnfe);


        if (!ga.foundOptima()) {

            foundOptima = false;

            if (SHOW_BISECTION) {
                printf("-");
                fflush(NULL);
            }
            break;
        }

        if (SHOW_BISECTION) {
            printf("+");
            fflush(NULL);
        }


        rec[0] = rec[1];
        rec[1] = rec[2];
        rec[2].n = popu;
        rec[2].gen = stGen.getMean();

        if (!foundOptima)
            rec[2].nfe = INF;
        else
            rec[2].nfe = stNFE.getMean();

        if (SHOW_BISECTION) printf(" : %f \n", rec[2].nfe);

    }


    if (SHOW_BISECTION) printf("Bisection phase 2\n");

    while ( ((rec[2].n-rec[0].n)*20 > rec[1].n) && (rec[2].n>rec[1].n+1) && (rec[1].n>rec[0].n+1)) {

        q1.n = (rec[0].n + rec[1].n) / 2;

        if (SHOW_BISECTION) printf("[%d]: ", q1.n);

        foundOptima = true;

        for (int j=0; j<numConvergence; j++) {
            // Get fitness function
            auto fitnessFunction = getFitnessFunction(static_cast<FitnessType>(fitnessType));
            
            DSMGA2 ga(problemSize, q1.n, MAX_GEN, -1, fitnessFunction);
            if (!ga.foundOptima()) {
                foundOptima = false;
                if (SHOW_BISECTION) {
                    printf("-");
                    fflush(NULL);
                }
                break;
            }
            if (SHOW_BISECTION) {
                printf("+");
                fflush(NULL);
            }
            if (j==0) {
                stGen.reset();
                stLS.reset();
                stNFE.reset();
            }
            stGen.record(ga.getGeneration());
            stNFE.record(Chromosome::hitnfe);
            stLS.record(Chromosome::lsnfe);
        }

        q1.gen = stGen.getMean();
        if (foundOptima)
            q1.nfe = stNFE.getMean();
        else
            q1.nfe = INF;


        if (SHOW_BISECTION) printf(" : %f \n", q1.nfe);


        q3.n = (rec[1].n + rec[2].n) / 2;

        if (SHOW_BISECTION) printf("[%d]: ", q3.n);

        foundOptima = true;

        for (int j=0; j<numConvergence; j++) {
            // Get fitness function
            auto fitnessFunction = getFitnessFunction(static_cast<FitnessType>(fitnessType));
            
            DSMGA2 ga(problemSize, q3.n, MAX_GEN, -1, fitnessFunction);
            if (!ga.foundOptima()) {
                foundOptima = false;
                if (SHOW_BISECTION) {
                    printf("-");
                    fflush(NULL);
                }
                break;
            }
            if (SHOW_BISECTION) {
                printf("+");
                fflush(NULL);
            }
            if (j==0) {
                stGen.reset();
                stLS.reset();
                stNFE.reset();
            }
            stGen.record(ga.getGeneration());
            stNFE.record(Chromosome::hitnfe);
            stLS.record(Chromosome::lsnfe);
        }

        q3.gen = stGen.getMean();
        if (foundOptima) {
            q3.nfe = stNFE.getMean();
        } else
            q3.nfe = INF;

        if (SHOW_BISECTION) printf(" : %f \n", q3.nfe);

        if (rec[1].nfe < q1.nfe && rec[1].nfe < q3.nfe) {
            rec[0] = q1;
            rec[2] = q3;
        } else if (q1.nfe < rec[1].nfe && q1.nfe < q3.nfe) {
            rec[2] = rec[1];
            rec[1] = q1;
        } else { // q3nfe smallest
            rec[0] = rec[1];
            rec[1] = q3;
        }
    };



    if (fitnessType == 4)
        freeNKWAProblem(&nkwa);

    printf("population: %d\n", rec[1].n);
    printf("generation: %f\n", rec[1].gen);
    printf("NFE: %f\n", rec[1].nfe);


    return EXIT_SUCCESS;

}

