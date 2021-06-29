#include "Tree.h"
#include <cmath>
#include <cstdlib>



Tree::Tree(int depth) {
    this->depth = depth;
    n = pow(2, depth);
    maxLatency = 2 * depth;
    edges.resize(depth);
}

int Tree::getMaxLatency() {
    return maxLatency;
}

float Tree::random_access(int times) {
    int accumulated_latency = 0;
    for (int i = 0; i < times; ++i)
    {
        bool flag = true;
        for (int j = 0; j < depth; ++j) {
            int node1 = rand() % 3;
            int node2 = rand() % 3;
        }
    }
}