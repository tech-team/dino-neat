#include <iostream>

#include "genetic.h"

int main() {
    for (int i = 0; i < 100; ++i) {
    srand(100);
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

