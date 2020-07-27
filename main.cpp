#include <iostream>
#include "dijkstras.h"


// If 2 nodes are not neighbours set the distances between them to this in the input 2D Graph
#define INF 100

// Input graph 
int graph[6][6] = { {0,7,9,INF,INF,14},
                    {7,0,10,15,INF,INF},
                    {9,10,0,11,INF,2},
                    {INF,15,11,0,6,INF},
                    {INF,INF,INF,6,0,9},
                    {14,INF,2,INF,9,0} };

// No of vertices in the graph. No need to handle.It is automatically calculated from the input 2D Array.
#define V int(  sizeof(graph)/sizeof(graph[0]) )

int main(){

    int source = 0; //TOD: from user input
    Dijkstra D(source,V,INF);
    
    D.setInput(&graph[0][0]);
    D.printInputGraph();
    D.run();
    D.printDistanceArray();
    std::cout << "Tracing path for all nodes: " << std::endl;
    for(int i=0;i<V;i++){
        std::cout << "For node: " << i << std::endl;
        D.TracePath(i);
        std::cout << std::endl;
    }
    std::cout << "Program ran successfully!!!" << std::endl;
    return 0;
}