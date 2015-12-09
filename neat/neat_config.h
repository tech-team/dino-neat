#ifndef NEATCONFIG_H
#define NEATCONFIG_H

#include "net.h"

#include <cstdint>

struct NeatConfig {
    Net::Config net_conf;
    uint32_t population_size = 10;
    uint32_t selection_count = 5;
    uint32_t crossovers_count = 10;
    int iterations_count = 5;

    double crossover_edge_enable_prob = 0.5;

    double mutate_weights_prob = 0.4;
    double mutate_add_connection_prob = 0.3;
    double mutate_add_node_prob = 0.3;
    double mutate_weights_petrurb_prob = 0.9;
    double mutate_weights_step = 0.2;

    double dist_excess_ratio = 0.2;
    double dist_disjoint_ratio = 0.5;
    double dist_avg_weights_raio = 0.3;
};

#endif // NEATCONFIG_H
