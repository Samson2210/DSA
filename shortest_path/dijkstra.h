#ifndef DISKTRA
#define DISKTRA
#define V 5

//dist[] = stores the distance to each vertex/node from the source 
//sptSet[] = stores the a boolean variable for each node/vertex i.e if its visited or not
int minDistance(int dist[], bool sptSet[]);
void printSolution(int dist[]);
void dijkstra(int graph[V][V], int src);

#endif