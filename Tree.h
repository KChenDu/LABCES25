#ifndef LABCES25_TREE_H
#define LABCES25_TREE_H
#include <vector>

class Tree {
private:
    int depth, n, maxLatency;
    std::vector<int> edges;

    int access(int node1, int node2);

public:
    explicit Tree(int depth);
    int getMaxLatency();
    float random_access(int times);
    int max_accessed_level();
    int max_accessed_level_value();
    void clear();
};


#endif //LABCES25_TREE_H
