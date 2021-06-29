#include "Hypercube.h"
#include <cstdlib>
#include <iostream>
#include <cmath>

Hypercube::Hypercube(int dimension) {
    this->dimension = dimension;
}

int Hypercube::getMaxLatency() {
    return dimension;
}

float Hypercube::random_access(int times) {
    int accumulated_latency = 0;
    for (int i = 0; i < times; ++i)
    {
        int node1 = rand() % static_cast<int>(pow(2, dimension)), node2;
        do
            node2 = rand() % static_cast<int>(pow(2, dimension));
        while (node1 == node2);
        while ((node1 != 0) || (node2 != 0))
        {
            if ((node1 & 1) != (node2 & 1))
                ++accumulated_latency;
            node1 >>= 1;
            node2 >>= 1;
        }
    }
    return static_cast<float>(accumulated_latency) / static_cast<float>(times);
}