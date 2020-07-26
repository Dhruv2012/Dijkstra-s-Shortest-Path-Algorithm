#include <iostream>
#include "dijkstras.h"

// Input graph 
int graph[6][6] = { {0,7,9,100,100,14},
                    {7,0,10,15,100,100},
                    {9,10,0,11,100,2},
                    {100,15,11,0,6,100},
                    {100,100,100,6,0,9},
                    {14,100,2,100,9,0} };

// No of vertices in the graph
#define V int(  sizeof(graph)/sizeof(graph[0]) )

int main(){

    int source = 0; //TOD: from user input
    Dijkstra D(source,V);
    D.setInput((int**)graph);
    D.printInputGraph();
    std::cout << "Program runs without errors" << std::endl;
    return 0;
}