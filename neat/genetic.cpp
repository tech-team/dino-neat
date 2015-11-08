#include "genetic.h"

#include <algorithm>
#include <iostream>

Genetic::Genetic(const Genetic::Config& conf)
    : conf_(conf) {
    for (int i = 0; i < conf.population_size; ++i) {
        population_.emplace_back(std::move(Chromosome(new Net(conf.net_conf))));
    }
}

int Genetic::elapsed_iterations() const {
    return elapsed_iterations_;
}

void Genetic::start() {
    while (elapsed_iterations_ < conf_.iterations_count) {
        iteration();
        ++elapsed_iterations_;
        std::cout << "Iteration #" << elapsed_iterations_ << std::endl;
    }
}

void Genetic::iteration() {
    evalPopulation();
    sortPopulation();

    for (auto& ch : population_) {
        ch.mutateWeights(1);
        ch.mutateStructure(1);
    }
    // mutate
    // crossover
}

void Genetic::evalPopulation() {
    for (auto& ch : population_) {
        ch.set_fitness(evalFitness(ch));
    }
}

double Genetic::evalFitness(Chromosome& ch) {
    // start game
    while (false) {
        std::vector<double> input(conf_.net_conf.input_size); // get input from game
        auto output = ch.net()->activate(input);
        // apply output
    }

    //return score
    return 0;
}

void Genetic::sortPopulation() {
    std::sort(population_.begin(), population_.end(), [](const Chromosome& ch1, const Chromosome& ch2) {
        return ch1.fitness() < ch2.fitness();
    });
}
