#include "genetic.h"

#include <algorithm>
#include <iostream>
#include <random>

#include "dino/game.h"
#include "util.h"

Genetic::Genetic(const NeatConfig& conf)
    : conf_(conf) {
    for (size_t i = 0; i < conf.population_size; ++i) {
        population_.emplace_back(std::move(Chromosome(random_, conf_, new Net(random_, conf.net_conf))));
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

Random& Genetic::random() {
    return random_;
}

void Genetic::iteration() {
    evalPopulation();
    sortPopulation();

    size_t maximum_population = std::min((size_t) conf_.population_size, population_.size());
    population_.erase(population_.begin() + maximum_population, population_.end());

    auto innov_getter = dynamic_cast<InnovationNumberGetter*>(this);
    for (auto& ch : population_) {
        if (random_.nextDouble() < conf_.mutate_weights_prob) {
            ch.mutateWeights();
        }
        if (random_.nextDouble() < conf_.mutate_add_connection_prob) {
            ch.mutateAddConnection(innov_getter);
        }
        if (random_.nextDouble() < conf_.mutate_add_node_prob) {
            ch.mutateAddNode(innov_getter);
        }
        ch.set_fitness(0);
    }

    for (uint32_t i = 0; i < conf_.crossovers_count; ++i) {
        std::cout << "crossover #" << i << std::endl;
        int p1 = random_.nextInt(0, std::min((size_t) conf_.selection_count, population_.size()) - 1);
        int p2 = random_.nextInt(0, std::min((size_t) conf_.selection_count, population_.size()) - 1);

        Chromosome ch = Chromosome::crossover(population_.at(p1), population_.at(p2));

        if (random_.nextDouble() < conf_.mutate_weights_prob) {
            ch.mutateWeights();
        }
        if (random_.nextDouble() < conf_.mutate_add_connection_prob) {
            ch.mutateAddConnection(innov_getter);
        }
        if (random_.nextDouble() < conf_.mutate_add_node_prob) {
            ch.mutateAddNode(innov_getter);
        }

        population_.emplace_back(std::move(ch));
    }
}

void Genetic::evalPopulation() {
    for (auto& ch : population_) {
        if (ch.fitness() <= 0) {
            ch.set_fitness(evalFitness(ch));
        }
    }
}

double Genetic::evalFitness(Chromosome& ch) {
    // start game
    Game game(60);

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
