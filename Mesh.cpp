#include "Mesh.h"
#include <cstdlib>
#include <iostream>

int Mesh::access(std::vector<int> node1, std::vector<int> node2) {
    int latency = 0;
    if (node1[0] > node2[0]) {
        while (node1[0] > node2[0]) {
            //std::cout << node1[0] << " " << node2[0] << std::endl;
            --node1[0];
            ++latency;
            ++horizontal[node1[0]][node1[1]];
        }
        //std::cout << node1[0] << " " << node2[0] << std::endl;
    }
    else if (node1[0] < node2[0]) {
        while (node1[0] < node2[0]) {
            //std::cout << node1[1] << " " << node2[1] << std::endl;
            ++latency;
            ++horizontal[node1[0]][node1[1]];
            ++node1[0];
        }
    }
    //std::cout << "analising vertical" << std::endl;
    if (node1[1] > node2[1]) {
        while (node1[1] > node2[1]) {
            //std::cout << node1[1] << " " << node2[1] << std::endl;
            --node1[1];
            ++latency;
            ++vertical[node1[1]][node1[0]];
        }
        //std::cout << node1[1] << " " << node2[1] << std::endl;
    }
    else if (node1[1] < node2[1]) {
        while (node1[1] < node2[1]) {
            //std::cout << node1[1] << " " << node2[1] << std::endl;
            ++latency;
            //std::cout << node1[1] << " " << node2[1] << std::endl;
            ++vertical[node1[1]][node1[0]];
            ++node1[1];
        }
    }
    return latency;
}

Mesh::Mesh(int side) {
    this->side = side;
    maxLatency = 2 * (side - 1);
    horizontal.resize(side - 1);
    for (int i = 0; i < side - 1; ++i)
        horizontal[i].resize(side);
    vertical.resize(side - 1);
    for (int i = 0; i < side - 1; ++i)
        vertical[i].resize(side);
}

int Mesh::getMaxLatency() {
    return maxLatency;
}

float Mesh::random_access(int times) {
    int accumulated_latency = 0;
    for (int i = 0; i < times; ++i) {
        std::vector<int> node1 {rand() % side, rand() % side}, node2;
        do
            node2 = {rand() % side, rand() % side};
        while (node1 == node2);
        accumulated_latency += access(node1, node2);
    }
    return static_cast<float>(accumulated_latency) / static_cast<float>(times);
}

void Mesh::print_most_visited_edge() {
    bool flag = 0;
    int max = -1, posx, posy;
    for (int i = 0; i < horizontal.size(); ++i) {
        for (int j = 0; j < horizontal[i].size(); ++j) {
            if (horizontal[i][j] > max) {
                max = horizontal[i][j];
                posx = i;
                posy = j;
            }
        }
    }
    for (int i = 0; i < vertical.size(); ++i) {
        for (int j = 0; j < vertical[i].size(); ++j) {
            if (vertical[i][j] > max) {
                flag = 1;
                max = vertical[i][j];
                posx = i;
                posy = j;
            }
        }
    }
    if (flag == 0) {
        std::cout << "most accessed edge: horizontal edge(" << "(" << posx << ", " << posy << ") ";
        std::cout << horizontal[posx][posy] << " times";
    } else {
        std::cout << "most accessed edge: vertical edge (" << posx << " " << posy << ") ";
        std::cout << vertical[posx][posy] << " times";
    }
}