#include <iostream>

#include "genetic.h"
#include "util.h"

int main() {
    srand(100);
    RandomGenerator::instance(RandomGeneratorId::GENETIC).srand(100);

    Net::Config net_conf;
    net_conf.input_size = 324;
    net_conf.output_size = 1;

    NeatConfig conf;
    conf.net_conf = net_conf;
    conf.iterations_count = 100;
    conf.population_size = 10;
    conf.mutate_structure_prob = 1;
    conf.mutate_weights_prob = 1;

    Genetic g(conf);
    g.start();
    std::cout << "fin" << std::endl;
}

