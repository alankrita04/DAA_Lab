
#include <stdio.h>

#define INF 9999
#define MAX 10

void dijkstra(int graph[MAX][MAX], int n, int src)
{
    int dist[MAX], visited[MAX];
    int i, j, u, min;

    // Initialization
    for (i = 0; i < n; i++)
    {
        dist[i] = INF;
        visited[i] = 0;
    }

    dist[src] = 0;

    // Find shortest paths
    for (i = 0; i < n - 1; i++)
    {
        min = INF;
        u = -1;

        // Find minimum distance unvisited vertex
        for (j = 0; j < n; j++)
        {
            if (!visited[j] && dist[j] < min)
            {
                min = dist[j];
                u = j;
            }
        }

        if (u == -1)
            break;

        visited[u] = 1;

        // Update distances of neighbours
        for (j = 0; j < n; j++)
        {
            if (!visited[j] && graph[u][j] != 0 &&
                dist[u] + graph[u][j] < dist[j])
            {
                dist[j] = dist[u] + graph[u][j];
            }
        }
    }

    // Display shortest distances
    printf("\nShortest distances from source %d:\n", src);

    for (i = 0; i < n; i++)
    {
        printf("To vertex %d = ", i);

        if (dist[i] == INF)
            printf("Infinity\n");
        else
            printf("%d\n", dist[i]);
    }
}

int main()
{
    int graph[MAX][MAX];
    int n, i, j, src;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter source vertex (0 to %d): ", n - 1);
    scanf("%d", &src);

    dijkstra(graph, n, src);

    return 0;
}
