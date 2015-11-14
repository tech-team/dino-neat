#ifndef NEATCONFIG_H
#define NEATCONFIG_H

#include "net.h"

struct NeatConfig {
    Net::Config net_conf;
    int population_size = 10;
    int iterations_count = 5;
    double edge_enable_prob = 1.0;
};

#endif // NEATCONFIG_H
