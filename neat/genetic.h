#ifndef GENETIC_H
#define GENETIC_H

#include "chromosome.h"
#include "net.h"


class Genetic
{
public:
    struct Config {
        Net::Config net_conf;
        int population_size;
        int iterations_count;
    };

    using Population = std::vector<Chromosome>;

    Genetic(const Genetic::Config& conf);

    int elapsed_iterations() const;
    void start();

private:
    void iteration();

    // genetic operators
    void evalPopulation();
    double evalFitness(Chromosome& ch);
    void sortPopulation();

    Genetic::Config conf_;
    Population population_;
    int elapsed_iterations_ = 0;
};

#endif // GENETIC_H
