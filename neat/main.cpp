#include <iostream>

#include "genetic.h"

int main() {
    Net::Config net_conf;
    net_conf.input_size = 3;
    net_conf.output_size = 1;

    Genetic::Config conf;
    conf.net_conf = net_conf;
    conf.iterations_count = 10;
    conf.population_size = 5;

    Genetic g(conf);
    g.start();
}

