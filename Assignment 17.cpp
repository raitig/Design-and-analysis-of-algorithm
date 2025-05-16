// Write a program in c to find the shortest path fromn a given node to all other nodes in a graph using the bellmanford algorithm and demonstrate how it performs for a graph having negative edges.
#include <stdio.h>
#include <stdlib.h>
#define INF 99
typedef struct{
	int src, dest, weight;
} Edge;
int main(){
	int V;
	printf(" Enter the number of vertices :");
	scanf("%d", &V);
	int adj[V][V];
	printf(" Enter the adjacency matrix (use %d to represent no edge):\n", INF);
	for(int i = 0; i < V; i++){
		for(int j = 0; j < V; j++){
			scanf("%d", &adj[i][j]);
		}
	}
	int edgecount = 0;
	for(int i = 0; i < V; i++){
		for(int j = 0; j < V; j++){
			if(adj[i][j] != INF && i !=j){
				edgecount++;
			}
		}
	}
	Edge* edges = (Edge*)malloc(edgecount * sizeof(Edge));
	int idx = 0;
	for (int i = 0; i < V; i++){
		for(int j = 0; j < V; j++){
			if(adj[i][j] != INF && i != j){
				edges[idx].src = i;
				edges[idx].dest = j;
				edges[idx].weight = adj[i][j];
				idx++;
			}
		}
	}
	int src;
	printf("Enter the source vertex : ");
	scanf("%d",&src);
	int dist[V];
	for(int i = 0; i < V; i++){
		dist[i] = INF;
	}
	dist[src] = 0;
	int hasNegativecycle = 0;
	for( int i = 0; i < V; i++){
		for(int j = 0; j < edgecount; j++){
			int u = edges[j].src;
			int v = edges[j].dest;
			int wt = edges[j].weight;
			if(dist[u] != INF && dist[u] + wt < dist[v]){
				if(i == V - 1){
					hasNegativecycle = 1;
					break;
				}
				dist[v] = dist[u] + wt;
			}
		}
	}
	if (hasNegativecycle){
		printf("Graph contains a negative weight cycle\n");
	}else{
		printf("Shortest distance from source vertex %d:\n",src);
		for(int i = 0; i < V; i++){
			if(dist[i] == INF)
			printf("Vertex %d: INF\n", i);
			else
			printf("Vertex %d: %d\n",i,dist[i]);
		}
	}
	free(edges);
	return 0;
}