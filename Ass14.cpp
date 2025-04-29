// Write a program in c to construct the minimum spanning tree from any direction or undirected graph using prim's algorithm.
#include<stdio.h>
#define MAX 10
#define INF 9999
int main (){
	int cost[MAX][MAX];
	int visited[MAX] = {0};
	int n,i,j,edges = 0;
	int min, a, b;
	printf("Enter number of vertices : ");
	scanf("%d",&n);
	printf("Enter cost adjacency matrix (0 if no edge):\n");
	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			scanf("%d", &cost[i][j]);
			if(cost[i][j] == 0)
			cost[i][j] = INF;
		}
	}
	visited[0] = 1;
	printf("Edges in minimun spaning Tree : \n");
	while (edges< n - 1){
		min = INF;
		for( i = 0; i < n; i++){
			if(visited[i]){
				for(j = 0; j < n; j++){
					if(!visited[j] && cost[i][j] < min){
						min = cost[i][j];
						a = i;
						b = j;
					}
				}
			}
		}
		printf("%d - %d : %d\n", a, b, cost[a][b]);
		visited[b] = 1;
		edges++;
	}
	return 0;
}
