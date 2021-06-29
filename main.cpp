#include <iostream>
#include "LinearArray.h"
#include "Ring.h"
#include "Hypercube.h"
#include "Mesh.h"

int main() {
    //LinearArray a(16);
    // Ring a(16);
    Hypercube a(4);
    //Mesh a(4);
    std::cout << "max latency: " << a.getMaxLatency() << std::endl;
    std::cout << "mean latency: " << a.random_access(1024) << std::endl;
    //a.print_most_visited_edge();
    //std::cout << "most accessed edge: " << a.max_accessed_edge() << "(";
    //std::cout << a.max_accessed_edge_value() << " times)";
    return 0;
}
