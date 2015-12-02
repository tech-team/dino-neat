#ifndef NEATCONFIG_H
#define NEATCONFIG_H

#include "net.h"

#include <cstdint>

struct NeatConfig {
    Net::Config net_conf;
    uint32_t population_size = 10;
    uint32_t selection_count = 5;
    int iterations_count = 5;
    double edge_enable_prob = 1.0;
};

#endif // NEATCONFIG_H
