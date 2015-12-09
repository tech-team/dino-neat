#include <iostream>

#include "genetic.h"
#include "util.h"

int main() {
    Net::Config net_conf;
    net_conf.input_size = 324;
    net_conf.output_size = 1;

    NeatConfig conf;
    conf.net_conf = net_conf;
    conf.iterations_count = 1000;
    conf.population_size = 20;

    conf.crossovers_count = 5;

    conf.mutate_weights_prob = 0.4;
    conf.mutate_add_connection_prob = 0.5;
    conf.mutate_add_node_prob = 0.3;
    conf.mutate_weights_petrurb_prob = 0.9;
    conf.mutate_weights_step = 0.2;

    Genetic g(conf);
    g.start();
    std::cout << "fin" << std::endl;
}

