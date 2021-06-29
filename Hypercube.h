#ifndef LABCES25_HYPERCUBE_H
#define LABCES25_HYPERCUBE_H


class Hypercube {
    int dimension;

public:
    explicit Hypercube(int dimension);
    int getMaxLatency();
    float random_access(int times);
};


#endif //LABCES25_HYPERCUBE_H
