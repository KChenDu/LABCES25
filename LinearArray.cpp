#include "LinearArray.h"
#include <cstdlib>

int LinearArray::access(int node1, int node2) {
    for (int i = node1; i < node2; ++edges[i++]);
    return node2 - node1;
}

LinearArray::LinearArray(int n_nodes) {
    n = n_nodes;
    maxLatency = --n_nodes;
    edges.resize(n_nodes);
}

int LinearArray::getMaxLatency() {
    return maxLatency;
}

float LinearArray::random_access(int times) {
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

int LinearArray::max_accessed_edge() {
    return std::max_element(edges.begin(), edges.end()) - edges.begin();
}

int LinearArray::max_accessed_edge_value() {
    return *std::max_element(edges.begin(), edges.end());
}

void LinearArray::clear() {
    for (int& edge : edges)
        edge = 0;
}