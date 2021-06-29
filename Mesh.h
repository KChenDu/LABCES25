#ifndef LABCES25_MESH_H
#define LABCES25_MESH_H
#include <vector>

class Mesh {
private:
    int side, maxLatency;
    std::vector<std::vector<int>> horizontal, vertical;

    int access(std::vector<int> node1, std::vector<int> node2);

public:
    explicit Mesh(int side_value);
    int getMaxLatency();
    float random_access(int times);
    void print_most_visited_edge();
    void clear();
};


#endif //LABCES25_MESH_H
