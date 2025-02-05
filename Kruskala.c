#include <stdio.h>

int find(int parent[], int i) {
    if (parent[i] == i)
        return i;
    return parent[i] = find(parent, parent[i]);  // Path compression
}

void unionSets(int parent[], int rank[], int x, int y) {
    int rootX = find(parent, x);
    int rootY = find(parent, y);

    if (rank[rootX] > rank[rootY])
        parent[rootY] = rootX;
    else if (rank[rootX] < rank[rootY])
        parent[rootX] = rootY;
    else {
        parent[rootY] = rootX;
        rank[rootX]++;
    }
}

void sortEdges(int edges[][3], int E) {
    for (int i = 0; i < E - 1; i++) {
        for (int j = 0; j < E - i - 1; j++) {
            if (edges[j][2] > edges[j + 1][2]) {
                int temp1 = edges[j][0], temp2 = edges[j][1], temp3 = edges[j][2];
                edges[j][0] = edges[j + 1][0];
                edges[j][1] = edges[j + 1][1];
                edges[j][2] = edges[j + 1][2];
                edges[j + 1][0] = temp1;
                edges[j + 1][1] = temp2;
                edges[j + 1][2] = temp3;
            }
        }
    }
}

void kruskal(int edges[][3], int V, int E) {
    int parent[V];
    int rank[V];

    for (int i = 0; i < V; i++) {
        parent[i] = i;
        rank[i] = 0;
    }
    sortEdges(edges, E);

    printf("Edges in the Minimum Spanning Tree:\n");
    int mstWeight = 0, edgeCount = 0;

    for (int i = 0; i < E && edgeCount < V - 1; i++) {
        int src = edges[i][0], dest = edges[i][1], weight = edges[i][2];

        if (find(parent, src) != find(parent, dest)) {
            printf("%d -- %d  | Weight: %d\n", src, dest, weight);
            mstWeight += weight;
            unionSets(parent, rank, src, dest);
            edgeCount++;
        }
    }

    if (edgeCount == V - 1) {
        printf("Total Weight of MST: %d\n", mstWeight);
    } else {
        printf("MST cannot be formed. Not enough edges.\n");
    }
}

int main() {
    int V, E;
    printf("Enter number of vertices: ");
    scanf("%d", &V);
    printf("Enter number of edges: ");
    scanf("%d", &E);

    int edges[E][3];
    printf("Enter edges (source destination weight):\n");
    for (int i = 0; i < E; i++) {
        scanf("%d %d %d", &edges[i][0], &edges[i][1], &edges[i][2]);
    }
    kruskal(edges, V, E);
    return 0;
}
