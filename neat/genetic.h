#ifndef GENETIC_H
#define GENETIC_H

#include <unordered_map>

#include "chromosome.h"
#include "net.h"
#include "innovation_number_getter.h"
#include "edge.h"
#include "neat_config.h"
#include "common/random.h"

class Genetic : public InnovationNumberGetter
{
public:
    using Population = std::vector<Chromosome>;

    Genetic(const NeatConfig& conf);

    int elapsed_iterations() const;
    void start();

    int getInnovNumber(Edge* edge) override;

    Random& random();

private:
    void iteration();

    // genetic operators
    void evalPopulation();
    double evalFitness(Chromosome& ch);
    void sortPopulation();

    NeatConfig conf_;
    Population population_;
    int innov_number_ = 0;
    int elapsed_iterations_ = 0;

    std::unordered_map<EdgeInfo, int> population_innovations_;

    Random random_;
};

#endif // GENETIC_H
