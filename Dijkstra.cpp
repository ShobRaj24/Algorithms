#include <iostream>
#include <limits.h>
#include <ctime>

#define V 4

int minDistance(int dist[], bool sptSet[])
{
    int min = INT_MAX;
    int min_index = 0;

    for (int v = 0; v < V; v++)
    {
        if (!sptSet[v] && dist[v] <= min)
        {
            min = dist[v];
            min_index = v;
        }
    }

    return min_index;
}

void printSolution(int dist[])
{
    std::cout << "Vertex \t Distance from Source" << std::endl;
    for (int i = 0; i < V; i++)
        std::cout << i << " \t\t" << dist[i] << std::endl;
}

void dijkstra(int graph[V][V], int src)
{
    int dist[V];
    bool sptSet[V];

    for (int i = 0; i < V; i++)
    {
        dist[i] = INT_MAX;
        sptSet[i] = false;
    }

    dist[src] = 0;

    for (int count = 0; count < V - 1; count++)
    {
        int u = minDistance(dist, sptSet);
        sptSet[u] = true;

        for (int v = 0; v < V; v++)
        {
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
        }
    }

    printSolution(dist);
}

int main()
{
    int src;
    clock_t start = clock();

    std::cout << "\nEnter the source city:";
    std::cin >> src;

    int graph[V][V] = {
        {0, 4, 0, 8},
        {4, 0, 8, 0},
        {0, 8, 0, 7},
        {8, 0, 7, 0}};

    dijkstra(graph, src);

    clock_t end = clock();
    double time = double(end - start) / double(CLOCKS_PER_SEC);
    std::cout << "\nEXECUTION TIME :" << std::fixed << time;

    return 0;
}
