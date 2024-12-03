/***************************************************************************
 *   Copyright (C) 2015 by TEIL                                            *
 ***************************************************************************/

#include <cstdio>
#include <cstring>
#include <functional>
#include "chromosome.h"
#include "fitness_functions.h"

std::function<double(const Chromosome&)> Chromosome::customFunction;

Chromosome::Chromosome() {
    length = 0;
    lengthLong = 0;
    gene = NULL;
    evaluated = false;
}

Chromosome::Chromosome(int n_length) {
    gene = NULL;
    init(n_length);
}

Chromosome::~Chromosome() {
    if (gene != NULL) delete[] gene;
}

void Chromosome::init(int _length) {
    length = _length;
    lengthLong = quotientLong(length) + 1;

    if (gene != NULL)
        delete[] gene;

    gene = new unsigned long[lengthLong];
    gene[lengthLong - 1] = 0;

    evaluated = false;
}

int Chromosome::getVal(int index) const {
    assert(index >= 0 && index < length);
    int q = quotientLong(index);
    int r = remainderLong(index);
    return (gene[q] & (1lu << r)) ? 1 : 0;
}

void Chromosome::setVal(int index, int val) {
    assert(index >= 0 && index < length);
    if (getVal(index) == val) return;
    setValF(index, val);
    key ^= zKey[index];
}

double Chromosome::evaluate() {
    if (!evaluated) {
        nfe++;
        
        if (function == CUSTOM && customFunction != nullptr) {
            fitness = customFunction(*this);
        } else {
            switch (function) {
                case ONEMAX:
                    fitness = oneMaxFitness(*this);
                    break;
                case MKTRAP:
                    fitness = mkTrapFitness(*this);
                    break;
                case FTRAP:
                    fitness = fTrapFitness(*this);
                    break;
                case CYCTRAP:
                    fitness = cycTrapFitness(*this);
                    break;
                case NK:
                    fitness = nkFitness(*this);
                    break;
                case SPINGLASS:
                    fitness = spinGlassFitness(*this);
                    break;
                case SAT:
                    fitness = satFitness(*this);
                    break;
                default:
                    fitness = mkTrapFitness(*this);
                    break;
            }
        }
        
        if (CACHE)
            cache[key] = fitness;
            
        evaluated = true;
    }
    return fitness;
}

double Chromosome::getFitness() {
    if (evaluated)
        return fitness;
    else {
        fitness = evaluate();
        if (!hit && fitness > getMaxFitness()) {
            hit = true;
            hitnfe = nfe + lsnfe;
        }
        return fitness;
    }
}

bool Chromosome::GHC() {
    // Implement Hill Climbing algorithm
    bool improved = false;
    for (int i = 0; i < length; i++) {
        if (tryFlipping(i)) {
            improved = true;
        }
    }
    return improved;
}

void Chromosome::setValF(int index, int val) {
    assert(index >= 0 && index < length);
    int q = quotientLong(index);
    int r = remainderLong(index);

    if (val == 1)
        gene[q] |= (1lu << r);
    else
        gene[q] &= ~(1lu << r);

    evaluated = false;
}

void Chromosome::flip(int index) {
    assert(index >= 0 && index < length);
    int q = quotientLong(index);
    int r = remainderLong(index);

    gene[q] ^= (1lu << r);
    key ^= zKey[index];
    evaluated = false;
}

void Chromosome::initR(int _length) {
    length = _length;
    lengthLong = quotientLong(length) + 1;

    if (gene != NULL)
        delete[] gene;

    gene = new unsigned long[lengthLong];
    gene[lengthLong - 1] = 0;

    key = 0;
    for (int i = 0; i < length; i++) {
        int val = myRand.flip();
        setValF(i, val);
        if (val == 1)
            key ^= zKey[i];
    }

    evaluated = false;
}

Chromosome& Chromosome::operator=(const Chromosome& c) {
    if (this != &c) {
        if (lengthLong != c.lengthLong) {
            delete[] gene;
            lengthLong = c.lengthLong;
            gene = new unsigned long[lengthLong];
        }
        
        length = c.length;
        memcpy(gene, c.gene, sizeof(unsigned long) * lengthLong);
        fitness = c.fitness;
        evaluated = c.evaluated;
        key = c.key;
    }
    return *this;
}

unsigned long Chromosome::getKey() const {
    return key;
}

int Chromosome::getLength() const {
    return length;
}

double Chromosome::getMaxFitness() const {
    switch (function) {
        case ONEMAX:
            return length;
        case MKTRAP:
            return length / TRAP_K;
        case FTRAP:
            return length / 6;
        case CYCTRAP:
            return length / (TRAP_K - 1);
        case NK:
            return length; // This might need adjustment
        case SPINGLASS:
            return length * 2; // This might need adjustment
        case SAT:
            return 1.0; // This might need adjustment
        default:
            return length / TRAP_K;
    }
}

bool Chromosome::tryFlipping(int index) {
    assert(index >= 0 && index < length);
    
    // Store original fitness
    double originalFitness = getFitness();
    
    // Flip the bit
    flip(index);
    
    // Get new fitness
    double newFitness = getFitness();
    
    // If improvement, keep the change and return true
    if (newFitness > originalFitness) {
        return true;
    }
    
    // Otherwise, flip back and return false
    flip(index);
    return false;
}
