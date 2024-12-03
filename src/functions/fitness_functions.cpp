#include "fitness_functions.h"

double trap(int unitary, double fHigh, double fLow, int trapK) {
    if (unitary > trapK)
        return 0;

    if (unitary == trapK)
        return fHigh;
    else
        return fLow - unitary * fLow / (trapK-1);
}

double oneMaxFitness(const Chromosome& ch) {
    double result = 0;
    for (int i = 0; i < ch.getLength(); ++i)
        result += ch.getVal(i);
    return result;
}

double mkTrapFitness(const Chromosome& ch) {
    int i, j, u;
    int TRAP_M = ch.getLength() / TRAP_K;
    double result = 0;

    for (i = 0; i < TRAP_M; i++) {
        u = 0;
        for (j = 0; j < TRAP_K; j++)
            u += ch.getVal(i * TRAP_K + j);
        result += trap(u, 1.0, 0.8, TRAP_K);
    }
    return result;
}

double fTrapFitness(const Chromosome& ch) {
    double result = 0.0;
    for (int i = 0; i < ch.getLength()/6; ++i) {
        int u = 0;
        for (int j = 0; j < 6; ++j)
            u += ch.getVal(i*6+j);

        if (u == 0 || u == 6)
            result += 1.0;
        else if (u == 1 || u == 5)
            result += 0.0;
        else if (u == 2 || u == 4)
            result += 0.4;
        else // u == 3
            result += 0.8;
    }
    return result;
}

double cycTrapFitness(const Chromosome& ch) {
    int TRAP_M = ch.getLength() / (TRAP_K-1);
    double result = 0;
    
    for (int i = 0; i < TRAP_M; i++) {
        int u = 0;
        int idx = i * TRAP_K - i;
        for (int j = 0; j < TRAP_K; j++) {
            int pos = idx + j;
            if (pos == ch.getLength())
                pos = 0;
            u += ch.getVal(pos);
        }
        result += trap(u, 1.0, 0.8, TRAP_K);
    }
    return result;
}

double spinGlassFitness(const Chromosome& ch) {
    int *x = new int[ch.getLength()];
    
    for (int i = 0; i < ch.getLength(); i++)
        x[i] = ch.getVal(i) == 1 ? 1 : -1;
    
    double result = evaluateSPIN(x, &mySpinGlassParams);
    delete[] x;
    return result;
}

double nkFitness(const Chromosome& ch) {
    char *x = new char[ch.getLength()];
    
    for (int i = 0; i < ch.getLength(); ++i)
        x[i] = (char)ch.getVal(i);
    
    double result = evaluateNKProblem(x, &nkwa);
    delete[] x;
    return result;
}

double satFitness(const Chromosome& ch) {
    int *x = new int[ch.getLength()];
    
    for (int i = 0; i < ch.getLength(); ++i)
        x[i] = ch.getVal(i);
    
    double result = evaluateSAT(x, &mySAT);
    delete[] x;
    return result;
}

std::function<double(const Chromosome&)> getFitnessFunction(FitnessType type) {
    switch (type) {
        case FITNESS_ONEMAX:
            return oneMaxFitness;
        case FITNESS_MKTRAP:
            return mkTrapFitness;
        case FITNESS_FTRAP:
            return fTrapFitness;
        case FITNESS_CYCTRAP:
            return cycTrapFitness;
        case FITNESS_NK:
            return nkFitness;
        case FITNESS_SPINGLASS:
            return spinGlassFitness;
        case FITNESS_SAT:
            return satFitness;
        case FITNESS_CUSTOM:
            return Chromosome::customFunction;
        default:
            return nullptr;
    }
} 