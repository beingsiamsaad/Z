
#include <stdio.h>

void DFS(int v, int n, int G[n][n], int visited[n]);

int main() {
    int n;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    int G[n][n], visited[n];

    printf("\nEnter adjacency matrix of the graph:\n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &G[i][j]);
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            printf("%d ",G[i][j]);
        }
        printf("\n");
    }

    // Initialize visited array to 0 (unvisited)
    for(int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    printf("Enter the starting node : ");
    int start;
    scanf("%d", &start);
    printf("DFS Traversal:\t");
    DFS(start, n, G, visited);

    return 0;
}

void DFS(int start, int n, int G[n][n], int visited[n]) {
    printf("%d ", start);
    visited[start] = 1;

    for(int j = 0; j < n; j++) {
        if(!visited[j] && G[start][j] == 1) {
            DFS(j, n, G, visited);
        }
    }
}
