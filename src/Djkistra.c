#include <stdio.h>
#include <limits.h>

#define MAX 100
#define INF INT_MAX

int findMinDistance(int dist[], int visited[], int n) {
    int min = INF, min_index = -1;
    for (int v = 0; v < n; v++) {
        if (!visited[v] && dist[v] < min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

void printSolution(int dist[], int parent[], int n, int src) {
    printf("\nVertex\tDistance from Source\tPath");
    for (int i = 0; i < n; i++) {
        printf("\n%d -> %d\t\t", src, i);
        if (dist[i] == INF) {
            printf("INF\t\tNo path");
            continue;
        }
        printf("%d\t\t", dist[i]);
        printf("%d", i);
        int j = i;
        while (parent[j] != -1) {
            printf(" <- %d", parent[j]);
            j = parent[j];
        }
    }
    printf("\n");
}

void dijkstra(int graph[MAX][MAX], int n, int src) {
    int dist[MAX];
    int visited[MAX];
    int parent[MAX];

    for (int i = 0; i < n; i++) {
        dist[i] = INF;
        visited[i] = 0;
        parent[i] = -1;
    }

    dist[src] = 0;

    for (int count = 0; count < n - 1; count++) {
        int u = findMinDistance(dist, visited, n);
        if (u == -1) break; // All remaining vertices are unreachable

        visited[u] = 1;

        for (int v = 0; v < n; v++) {
            if (!visited[v] && graph[u][v] && dist[u] != INF && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                parent[v] = u;
            }
        }
    }

    printSolution(dist, parent, n, src);
}

int main() {
    int n, e, src;
    int graph[MAX][MAX] = {0};

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &e);

    printf("Enter weights for edges u & v (u v w):\n");
    for (int i = 0; i < e; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w;
        graph[v][u] = w; // comment this line if directed graph
    }

    printf("Enter source vertex: ");
    scanf("%d", &src);

    dijkstra(graph, n, src);

    return 0;
}
