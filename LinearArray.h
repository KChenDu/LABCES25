#ifndef LABCES25_LINEARARRAY_H
#define LABCES25_LINEARARRAY_H
#include <vector>


class LinearArray {
private:
    int n, maxLatency;
    std::vector<int> edges;

    int access(int node1, int node2);

public:
    explicit LinearArray(int n_nodes);
    int getMaxLatency();
    float random_access(int times);
    int max_accessed_edge();
    int max_accessed_edge_value();
    void clear();
};


#endif //LABCES25_LINEARARRAY_H
