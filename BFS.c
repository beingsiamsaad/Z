#include <stdio.h>
#include <stdbool.h>
#define MAX_VERTICES 100

void enqueue(int queue[], int *rear, int vertex) {
    queue[*rear] = vertex;
    (*rear)++;
}

int dequeue(int queue[], int *front) {
    int vertex = queue[*front];
    (*front)++;
    return vertex;
}

void bfs(int graph[MAX_VERTICES][MAX_VERTICES], int startVertex, int numVertices) {
    int queue[MAX_VERTICES];
    bool visited[MAX_VERTICES] = {false};
    int front = 0, rear = 0;
    visited[startVertex] = true;
    enqueue(queue, &rear, startVertex);

    while (front < rear) {
        int currentVertex = dequeue(queue, &front);
        printf("%d ", currentVertex);

        for (int i = 0; i < numVertices; i++) {
            if (graph[currentVertex][i] == 1 && !visited[i]) {
                visited[i] = true;
                enqueue(queue, &rear, i);
            }
        }
    }
}

int main() {
    int numVertices;
    printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);

    int graph[MAX_VERTICES][MAX_VERTICES];
    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
    int startVertex;
    printf("Enter the starting vertex: ");
    scanf("%d", &startVertex);

    printf("BFS:\t");
    bfs(graph, startVertex, numVertices);
    return 0;
}
