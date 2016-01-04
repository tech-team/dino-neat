#ifndef SPECIES_H
#define SPECIES_H

#include <vector>

#include "neat_config.h"
#include "chromosome.h"

class Species { // одна специя
public:
    Species(NeatConfig& conf);

    bool testChromosome(const Chromosome& ch);
    void addChromosome(const Chromosome& ch);

private:
    NeatConfig& conf_;
    std::vector<Chromosome> population_;
};

#endif // SPECIES_H
