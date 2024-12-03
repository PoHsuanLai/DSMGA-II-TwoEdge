/*
 * dsmga2.h
 *
 *  Created on: May 2, 2011
 *      Author: tianliyu
 */

#ifndef _DSMGA2_H_
#define _DSMGA2_H_

#include <list>
#include "chromosome.h"
#include "statistics.h"
#include "trimatrix.h"
#include "doublelinkedlistarray.h"
#include "fastcounting.h"
#include <pybind11/pybind11.h>
#include <functional>
#include <vector>
#include <unordered_map>

class DSMGA2 {
public:
    DSMGA2(int n_ell, 
           int n_nInitial, 
           int n_maxGen, 
           int n_maxFe, 
           std::function<double(const Chromosome&)> customFn);

    ~DSMGA2();

    void selection();
    void tournamentSelection();
    void oneRun(bool output = true);
    int doIt(bool output = true);
    void buildGraph();
    void mixing();
    
    void findMask(Chromosome& ch, std::list<int>& mask, int startNode);
    void findMask_size(Chromosome& ch, std::list<int>& mask, int startNode, int bound);
    void buildGraph_sizecheck();
    void restrictedMixing(Chromosome&);
    bool restrictedMixing(Chromosome& ch, std::list<int>& mask);
    void backMixing(Chromosome& source, std::list<int>& mask, Chromosome& des);
    void backMixingE(Chromosome& source, std::list<int>& mask, Chromosome& des);

    bool shouldTerminate();
    bool foundOptima();
    bool isSteadyState();
    bool converged();

    int getGeneration() const { return generation; }
    bool isInP(const Chromosome&) const;

    void genOrderN();
    void genOrderELL();

    void showStatistics();

    std::vector<int> getBest() const {
        std::vector<int> result(population[bestIndex].getLength());
        for (int i = 0; i < result.size(); i++) {
            result[i] = population[bestIndex].getVal(i);
        }
        return result;
    }

    double getBestFitness() const {
        return population[bestIndex].getFitness();
    }

public:
    int ell;
    int nCurrent;
    bool EQ;
    std::unordered_map<unsigned long, double> pHash;

    std::list<int>* masks;
    int* selectionIndex;
    int* orderN;
    int* orderELL;
    int selectionPressure;
    int maxGen;
    int maxFe;
    int repeat;
    int generation;
    int bestIndex;

    Chromosome* population;
    FastCounting* fastCounting;

    TriMatrix<double> graph;
    TriMatrix<double> graph_size;
    double previousFitnessMean;
    Statistics stFitness;

    double computeMI(double, double, double, double) const;
    void findClique(int startNode, std::list<int>& result);
    void buildFastCounting();
    int countXOR(int, int) const;
    int countOne(int) const;
    size_t findSize(Chromosome&, std::list<int>&) const;
    size_t findSize(Chromosome&, std::list<int>&, Chromosome&) const;

    double lastMax, lastMean, lastMin;
    int convergeCount;

    pybind11::function pyFunction;
};

#endif /* _DSMGA2_H_ */
