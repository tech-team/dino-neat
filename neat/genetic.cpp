#include "genetic.h"

#include <algorithm>
#include <iostream>
#include <random>

#include "dino/game.h"

Genetic::Genetic(const NeatConfig& conf)
    : conf_(conf) {
    for (int i = 0; i < conf.population_size; ++i) {
        population_.emplace_back(std::move(Chromosome(conf_, new Net(conf.net_conf))));
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

int Genetic::getInnovNumber(Edge* edge) {
    auto existing_edge = population_edges_.find(edge->edge_info());
    if (existing_edge == population_edges_.end()) {
        ++innov_number_;
        population_edges_[edge->edge_info()] = edge;
        return innov_number_;
    } else {
        return existing_edge->second->innovation();
    }
}

void Genetic::iteration() {
    evalPopulation();
    sortPopulation();

    for (auto& ch : population_) {
        ch.mutateWeights();
        ch.mutateStructure(this);
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
    Game game_(1);

    game_.subscribeOnUpdate([this, &ch, &game_] () {
        // state
        if (game_.is_game_over()) {
            game_.stop();
            return;
        }

        // I/O
        std::vector<double> input = game_.rasterizeWorld();
        auto output = ch.net()->activate(input);
        bool press_space = output[0] > 0;

        if (press_space) {
            sf::Event event;
            event.type = sf::Event::KeyPressed;
            event.key.code = sf::Keyboard::Space;

            game_.onKeyPressed(event);
        }
    });

    // blocking call
    game_.startEventLoop();

    // return score
    return game_.score();
}

void Genetic::sortPopulation() {
    std::sort(population_.begin(), population_.end(), [](const Chromosome& ch1, const Chromosome& ch2) {
        return ch1.fitness() < ch2.fitness();
    });
}
