#ifndef LABCES25_RING_H
#define LABCES25_RING_H
#include <vector>

class Ring {
private:
    int n, maxLatency;

    int access(int node1, int node2);

public:
    Ring(int n_node);
    int getMaxLatency();
    float random_access(int times);
    void clear();
};


#endif //LABCES25_RING_H
