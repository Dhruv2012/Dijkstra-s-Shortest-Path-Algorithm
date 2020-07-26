#include <iostream>
#include <bits/stdc++.h>
#pragma once

class Dijkstra{
    int N,src;          /// No of nodes,Source in the Algorithm.
    int **graph;       /// Input graph

    public:        
        std::vector<int> distance;     ///distance array wrt source to all nodes in the graph.
        
        Dijkstra(int source,int no_of_nodes);

        /** \brief Initializes distance array wrto source. Hence, Distance at source index is 0 and with the other indices is infinity(For convenience its set to -1 here). 
         * \param[in] source index
         */
        void init_distance();

        //setters and getters

        /** \brief Sets input 2D array as graph for the algorithm
         * \param[in] 2D array
         */
        void setInput(int **input){
            int* temp;
            graph = (int** )malloc(N * sizeof(*graph));
            temp = (int* )malloc(N  * N * sizeof(graph[0]));
            for (int i = 0; i < N; i++) {
                graph[i] = temp + (i * N);
            }

            std::cout << "N: " << N << std::endl;
            std::cout << sizeof(input)/sizeof(input[0]) << std::endl;
            for(int i = 0; i < N;i++){
                for(int j = 0; j <N;j++)
                       //graph[i][j] = input[i][j];                     
                       std::cout << input[i][j] << " ";
            }
           
        }

        void setSource(int source){
            src = source;
        }

        int getSource(){
            return src;
        }

        void printInputGraph(){
            for(int i=0;i<N;i++){
                for(int j=0;j<N;j++){
                    std::cout << graph[i][j] << " ";
                }
                std::cout << std::endl;
            }
        }
        
};
