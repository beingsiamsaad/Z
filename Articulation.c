
#include <stdio.h>
#define MAX 100

int visited[MAX];
int parent[MAX];
int low[MAX];
int disc[MAX];
int time = 0;
int ap[MAX];
int adj[MAX][MAX];

int min(int a, int b) {
    return a < b ? a : b;
}

void DFS(int V, int u) {
    visited[u] = 1;
    disc[u] = low[u] = ++time;
    int children = 0;

    for (int v = 0; v < V; v++) {
        if (adj[u][v] == 1 && visited[v] == 0) {
            children++;
            parent[v] = u;
            DFS(V, v);
            low[u] = min(low[u], low[v]);

            if (parent[u] == -1 && children > 1) {
                ap[u] = 1;
            } else if (parent[u] != -1 && low[v] >= disc[u]) {
                ap[u] = 1;
            }
        } else if (adj[u][v] == 1 && v != parent[u]) {
            low[u] = min(low[u], disc[v]);
        }
    }
}

int find_articulation_points(int V) {
    for (int i = 0; i < V; i++) {
        parent[i] = -1;
        visited[i] = 0;
        ap[i] = 0;
    }

    for (int i = 0; i < V; i++) {
        if (visited[i] == 0) {
            DFS(V, i);
        }
    }

    int count = 0;
    for (int i = 0; i < V; i++) {
        if (ap[i] == 1) {
            count++;
        }
    }

    return count;
}

int main() {
    int V, E;
    printf("Enter the number of Vertices and Edges: ");
    scanf("%d %d", &V, &E);

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            adj[i][j] = 0;
        }
    }

    printf("Enter the Adjacent pairs:");
    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = adj[v][u] = 1;
    }

    int count = find_articulation_points(V);
    printf("Number of articulation points: %d\n", count);

    printf("Articulation points: ");
    for (int i = 0; i < V; i++) {
        if (ap[i] == 1) {
            printf("%d ", i);
        }
    }
    printf("\n");
    return 0;
}
