#include <stdio.h>

void DFS(int v, int n, int G[n][n], int visited[n]);
void dfs1(int n, int graph[n][n], int visited[n], int stack[n], int v);
void dfs2(int n, int transpose[n][n], int visited[n], int v);
void findSCC(int n, int graph[n][n]);

int top = -1;

int main() {
    int n;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    int graph[n][n];

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    findSCC(n, graph);
    return 0;
}

void dfs1(int n, int graph[n][n], int visited[n], int stack[n], int v) {
    visited[v] = 1;
    for (int i = 0; i < n; i++) {
        if (!visited[i] && graph[v][i] == 1) {
            dfs1(n, graph, visited, stack, i);
        }
    }
    stack[++top] = v;
}

void dfs2(int n, int transpose[n][n], int visited[n], int v) {
    visited[v] = 1;
    printf("%d ", v);
    for (int i = 0; i < n; i++) {
        if (!visited[i] && transpose[v][i] == 1) {
            dfs2(n, transpose, visited, i);
        }
    }
}

void findSCC(int n, int graph[n][n]) {
    int visited[n];
    int stack[n];
    int transpose[n][n];

    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        if (visited[i] == 0) {
            dfs1(n, graph, visited, stack, i);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            transpose[i][j] = graph[j][i];
        }
    }

    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    while (top != -1) {
        int v = stack[top--];
        if (visited[v] == 0) {
            printf("\nSCC: ");
            dfs2(n, transpose, visited, v);
        }
    }
}
