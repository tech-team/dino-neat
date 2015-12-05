#include "genetic.h"

#include <algorithm>
#include <iostream>
#include <random>

#include "dino/game.h"
#include "util.h"

Genetic::Genetic(const NeatConfig& conf)
    : conf_(conf) {
    for (size_t i = 0; i < conf.population_size; ++i) {
        population_.emplace_back(std::move(Chromosome(conf_, new Net(conf.net_conf))));
    }
}

int Genetic::elapsed_iterations() const {
    return elapsed_iterations_;
}

void Genetic::start() {
    while (elapsed_iterations_ < conf_.iterations_count) {
        ++elapsed_iterations_;
        std::cout << "Iteration #" << elapsed_iterations_ << std::endl;
        iteration();
    }
}

int Genetic::getInnovNumber(Edge* edge) {
    auto existing_edge = population_innovations_.find(edge->edge_info());
    if (existing_edge == population_innovations_.end()) {
        ++innov_number_;
        population_innovations_[edge->edge_info()] = innov_number_;
        return innov_number_;
    } else {
        return existing_edge->second;
    }
}

void Genetic::iteration() {
    evalPopulation();
    sortPopulation();

    RandomGenerator& random = RandomGenerator::instance(RandomGeneratorId::GENETIC);
    for (auto& ch : population_) {
        if (random.rand() < conf_.mutate_weights_prob) {
            ch.mutateWeights();
        }
        if (random.rand() < conf_.mutate_structure_prob) {
            ch.mutateStructure(dynamic_cast<InnovationNumberGetter*>(this));
        }
    }

    if (elapsed_iterations_ != 1) {
        for (uint32_t i = 0; i < conf_.crossovers_count; ++i) {
            std::cout << "crossover #" << i << std::endl;
            int p1 = random.randInt(0, std::min((size_t) conf_.selection_count, population_.size()) - 1);
            int p2 = random.randInt(0, std::min((size_t) conf_.selection_count, population_.size()) - 1);

            Chromosome child = Chromosome::crossover(population_.at(p1), population_.at(p2));
            population_.emplace_back(std::move(child));
        }


        sortPopulation();

        size_t maximum_population = std::min((size_t) conf_.population_size, population_.size());
        population_.erase(population_.begin() + maximum_population, population_.end());    
    }    
}

void Genetic::evalPopulation() {
    for (auto& ch : population_) {
        ch.set_fitness(evalFitness(ch));
    }
}

double Genetic::evalFitness(Chromosome& ch) {
    // start game
    Game game(40);

    game.subscribeOnUpdate([this, &ch, &game] () {
        // state
        if (game.is_game_over()) {
            game.stop();
            return;
        }

        // I/O
        std::vector<double> input = game.rasterizeWorld();
        auto output = ch.net()->activate(input);
//        std::cout << "Output: " << output[0] << std::endl;
        bool press_space = output[0] > 0;

        sf::Event event;
        event.key.code = sf::Keyboard::Space;
        if (press_space) {
            event.type = sf::Event::KeyPressed;
            game.onKeyPressed(event);
        } else {
            event.type = sf::Event::KeyReleased;
            game.onKeyReleased(event);
        }
    });

    // blocking call
    game.startEventLoop();

    // return score
//    std::cout << "Score: " << game.score() << std::endl;
    return game.score();
}

void Genetic::sortPopulation() {
    std::sort(population_.begin(), population_.end(), [](const Chromosome& ch1, const Chromosome& ch2) {
        return ch1.fitness() < ch2.fitness();
    });
}
