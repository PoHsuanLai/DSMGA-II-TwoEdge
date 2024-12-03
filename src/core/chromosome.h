/***************************************************************************
 *   Copyright (C) 2011 by TEIL                                        *
 *                                                                         *
 ***************************************************************************/
#ifndef _CHROMOSOME_H
#define _CHROMOSOME_H

#include <unordered_map>
#include "global.h"
#include "nk-wa.h"
#include <functional>

using namespace std;

class Chromosome {

public:

    static std::function<double(const Chromosome&)> customFunction;
    static enum Function {
        ONEMAX=0,
        MKTRAP=1,
        FTRAP=2,
        CYCTRAP=3,
        NK=4,
        SPINGLASS=5,
        SAT=6,
        CUSTOM=7
    } function;


    Chromosome ();
    Chromosome (int n_ell);

    ~Chromosome ();

    bool hasSeen() const;

    bool GHC();
    void steepestDescent();

    void init (int _ell);
    void init0 (int _ell);
    void initR (int _ell);

    bool tryFlipping (int index);

    int getVal (int index) const;

    void setVal (int index, int val);

    unsigned long getKey () const;

    void setValF (int index, int val);

    void flip (int index);

    int getLength () const;

    void setLength ();

    double getMaxFitness () const;

    double evaluate ();

    bool isEvaluated () const;

    double getFitness ();

    bool operator== (const Chromosome & c) const;
    Chromosome & operator= (const Chromosome & c);

public:
    static int nfe;
    static int lsnfe;
    static int hitnfe;
    static bool hit;
    static unordered_map<unsigned long, double> cache;

protected:

    unsigned long *gene;
    int length;
    int lengthLong;
    double fitness;
    bool evaluated;
    unsigned long key;

};


#endif
