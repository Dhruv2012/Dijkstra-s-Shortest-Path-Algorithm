#include "dijkstras.h"

// Dijkstra Class Constructor
Dijkstra::Dijkstra(int source,int no_of_nodes){
    src = source;
    N = no_of_nodes;
    init_distance();
    std::cout << N << std::endl;
    for(int i=0;i<N;i++)
        std::cout << distance[i] << std::endl;
}

void Dijkstra::init_distance(){
    distance.assign(N,-1);
    distance[src] = 0;
}