#include <iostream>
#include <bits/stdc++.h>
#pragma once

typedef std::pair<int, int> ipair; 


class Dijkstra{
    int N,src,max_dist;          /// No of nodes, Source node in the Algorithm, Max distance between 2 nodes
    int **graph;                 /// Input graph
    std::vector <ipair> *adj;    /// A vector storing neighbouring vertices and weight/edges pair 
    std::vector<bool> visited;   /// A vector for storing information of visited vertices.
    std::vector<int> parent;     /// A vector for storing parent node for each node. For Path tracing.
    public:        
        std::vector<int> distance;     ///distance array wrt source to all nodes in the graph.
        
        Dijkstra(int source,int no_of_nodes,int max_distance);

        /** \brief Initializes distance array wrto source. 
        *   Hence, Distance at source index is 0 and with the other indices is infinity/max_distance(Max value in input 2D array). 
         * \param[in] source index
         */
        void init_distance();

        //setters and getters

        /** \brief Sets input 2D array as graph for the algorithm
         * \param[in] 2D array
         */
        void setInput(int *input);

        /** \brief Runs Dijkstras algo
         */
        void run();

        void setSource(int source){
            src = source;
        }

        int getSource(){
            return src;
        }
        
        /** \brief Traces path for specifed node
        *  \param[in] Input node for which path is to be traced
        */
        void TracePath(int j){
            if(parent[j]==-1){
                std::cout << j;
                return;
            }
            TracePath(parent[j]);
            std::cout << "-" << j;
        }

        void printInputGraph(){
            std::cout << "The input Graph is: " <<std::endl;
            for(int i=0;i<N;i++){
                for(int j=0;j<N;j++){
                    std::cout << graph[i][j] << " ";
                }
                std::cout << std::endl;
            }
        }

        /** \brief Returns distance information of all nodes from source
        */          
        std::vector<int> getDistanceArray(){
            return distance;
        }
        
        void printDistanceArray(){
            std::cout << std::endl;
            std::cout << "The Distance of all nodes from source is: " <<std::endl;
            for(int i=0;i<distance.size();i++){
                std::cout << distance[i] << " ";
            }
            std::cout << std::endl;
        }

        void printParentArray(){
            std::cout << "The Parent array obtained is: " <<std::endl;
            for(int i=0;i<parent.size();i++){
                std::cout << parent[i] << " ";
            }
            std::cout << std::endl;
        }
};
