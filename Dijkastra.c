#include <stdio.h>
#include <limits.h>

int min(int n, int dist[n], int visited[n]) {
    int min = INT_MAX, minIndex;
    for (int i = 0; i < n; i++) {
        if (!visited[i] && dist[i] <= min) {
            min = dist[i];
            minIndex = i;
        }
    }
    return minIndex;
}

void dijkstra(int n, int graph[n][n], int src) {
    int dist[n];
    int visited[n];
    for (int i = 0; i < n; i++) {
        dist[i] = INT_MAX;
        visited[i] = 0;
    }

    dist[src] = 0;
    for (int count = 0; count < n - 1; count++) {
        int u = min(n, dist, visited);
        visited[u] = 1;

        for (int v = 0; v < n; v++) {
            if (!visited[v] && graph[u][v] != INT_MAX && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }
    printf("Vertex \t Distance from Source\n");
    int sum = 0;
    for (int i = 0; i < n; i++) {
        if (dist[i] == INT_MAX) {
            printf("%d \t\t INF\n", i);
        } else {
            printf("%d \t\t %d\n", i, dist[i]);
            sum += dist[i];
        }
    }
    printf("\nTotal path cost: %d\n", sum);
}

int main() {
    int n;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    int graph[n][n];
    printf("Enter the adjacency matrix (use 0 for no edge):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
            if (i != j && graph[i][j] == 0) {
                graph[i][j] = INT_MAX;
            }
        }
    }
    int src;
    printf("Enter the source vertex (0 to %d): ", n - 1);
    scanf("%d", &src);
    if (src < 0 || src >= n) {
        printf("Invalid source vertex. Please restart the program.\n");
        return 1;
    }
    dijkstra(n, graph, src);
    return 0;
}
