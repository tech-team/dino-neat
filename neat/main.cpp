#include <iostream>

#include "genetic.h"
#include "util.h"

int main() {
    srand(100);
    RandomGenerator::instance(RandomGeneratorId::GENETIC).srand(100);

    for (int i = 0; i < 100; ++i) {
        Net::Config net_conf;
        net_conf.input_size = 324;
        net_conf.output_size = 1;

        NeatConfig conf;
        conf.net_conf = net_conf;
        conf.iterations_count = 10;
        conf.population_size = 5;



        Genetic g(conf);
        g.start();
        std::cout << "fin" << std::endl;
    }
}

