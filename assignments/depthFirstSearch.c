#include <stdio.h> 
#define max 10 
/* a function to build adjacency matrix of a graph */ 
void buildadjm(int adj[][max], int n) 
{ 
 int i,j; 
 for(i=0;i<n;i++) 
 {
 	for(j=0;j<n;j++) 
 	{ 
 		printf("enter 1 if there is an edge from %d to %d, otherwise enter 0 \n", i,j); 
 		scanf("%d",&adj[i][j]); 
 	} 
 }
} 
/* a function to visit the nodes in a depth-first order */ 
void dfs(int x,int visited[],int adj[][max],int n) 
{ 
 int j; 
 visited[x] = 1; 
 printf("The node visited id %d\n",x); 
 for(j=0;j<n;j++) 
 if(adj[x][j] ==1 && visited[j] ==0) 
 dfs(j,visited,adj,n); 
} 
int main() 
{ 
 int adj[max][max],node,n; 
 int i, visited[max]; 
 printf("enter the number of nodes in graph maximum = %d\n",max); 
 scanf("%d",&n); 
 buildadjm(adj,n); 
 for(i=0; i<n; i++) 
 visited[i] =0; 
 for(i=0; i<n; i++) 
 {
 	if(visited[i] ==0) 
 	dfs(i,visited,adj,n); 
 }
 getchar();
 return 0;
} 
