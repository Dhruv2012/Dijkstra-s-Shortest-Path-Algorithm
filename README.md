# Dijkstra-s-Shortest-Path-Algorithm
Shortest Path Algorithm to trace the shortest path between 2 nodes in an IP network

Min-Heap is used for extracting node with minimum distance instead of looping each time for every node. Algorithm ends when the queue is empty. 

Due to this, time complexity reduces from **O(mn) to O(mlogn)** where m: no of edges, n: no of nodes.

#### Run using:
```
g++ *.cpp -o main
./main
```
