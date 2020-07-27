#include "include/dijkstras.h"

// Dijkstra Class Constructor
Dijkstra::Dijkstra(int source,int no_of_nodes,int max_distance){
    src = source;           /// Initializes source,No of nodes & maximum distance.    
    N = no_of_nodes;
    max_dist = max_distance;
    adj = new std::vector<ipair>[N];
    parent.assign(N,-1);    /// Initializes parent for all nodes as -1 
}

/// Initializes distance array. distance[src] = 0 while the rest are set to a very high value(i.e. here max value in 2D array)
void Dijkstra::init_distance(){
    distance.assign(N,max_dist);
    distance[src] = 0;
} 

void Dijkstra::setInput(int *input){
    int* temp;
    graph = (int** )malloc(N * sizeof(*graph));
    temp = (int* )malloc(N  * N * sizeof(graph[0]));
    for (int i = 0; i < N; i++) {
        graph[i] = temp + (i * N);
    }

    std::cout << "N: " << N << std::endl;

    for(int i = 0; i < N;i++){
        for(int j = 0; j <N;j++){
                graph[i][j] = *(input + i*N + j);
                /// Store only the neigbhours of the node in adj
                if(graph[i][j] < max_dist)
                    adj[i].push_back( std::make_pair(j,graph[i][j]) );                     
        }
    }
    init_distance();
}

void Dijkstra::run(){                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                               
    
    std::priority_queue<ipair, std::vector<ipair>, std::greater<ipair> > pq;
    /// Push source into priority_queue
    pq.push(std::make_pair(0,src));
    visited.assign(N,false);
    
    int u = src,prev_u = src;   /// Present node, Previous visited node

    /// Loop until queue is empty
    while(!pq.empty()){

        /// Pop out nearest node
        u = pq.top().second;
        pq.pop();
        if(visited[u]==false){
            visited[u] = true;
            
            /// Loop for all neighbours of u stored in adj[u]
            for(auto i = adj[u].begin(); i != adj[u].end();i++){

                int v = (*i).first;
                int weight = (*i).second;

                ///Check if it was visited previously or it is the same node
                if(v!=u && visited[v]==false && (distance[v] > distance[u] + weight)){
                    /// Update the distance and parent of that node
                    distance[v] = distance[u] + weight;
                    parent[v] = u;
                    pq.push( std::make_pair(distance[v], v));
                }
            }
        }
        /// Store u in prev_u(previously visited). Useful for tracing the path back to source.
        prev_u = u;
    }
    
}
