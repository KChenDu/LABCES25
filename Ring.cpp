#include "Ring.h"
#include <cstdlib>

int Ring::access(int node1, int node2) {
    const int diff = node2 - node1;
    if (diff > n / 2)
        return n - diff;
    return diff;
}

Ring::Ring(int n_nodes) {
    n = n_nodes;
    maxLatency = n_nodes / 2;
}

int Ring::getMaxLatency() {
    return maxLatency;
}

float Ring::random_access(int times) {
    int accumulated_latency = 0;
    for (int i = 0; i < times; ++i)
    {
       int node1 = rand() % n, node2;
        do
            node2 = rand() % n;
        while (node1 == node2);
        accumulated_latency += access(std::min(node1, node2), std::max(node1, node2));
    }
    return static_cast<float>(accumulated_latency) / static_cast<float>(times);
}