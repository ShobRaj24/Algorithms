#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Graph {
public:
    Graph(int vertices);

    void addEdge(int v, int w);
    void BFS(int startVertex);

private:
    int vertices;
    vector<vector<int>> adjacencyList;
};

Graph::Graph(int vertices) {
    this->vertices = vertices;
    adjacencyList.resize(vertices);
}

void Graph::addEdge(int v, int w) {
    adjacencyList[v].push_back(w);
    adjacencyList[w].push_back(v); // Assuming an undirected graph
}

void Graph::BFS(int startVertex) {
    // Mark all vertices as not visited
    vector<bool> visited(vertices, false);

    // Create a queue for BFS
    queue<int> bfsQueue;

    // Enqueue the start vertex and mark it as visited
    bfsQueue.push(startVertex);
    visited[startVertex] = true;

    cout << "BFS traversal starting from vertex " << startVertex << ": ";

    while (!bfsQueue.empty()) {
        int currentVertex = bfsQueue.front();
        cout << currentVertex << " ";
        bfsQueue.pop();

        // Traverse all adjacent vertices of the current vertex
        for (const int &neighbor : adjacencyList[currentVertex]) {
            if (!visited[neighbor]) {
                // Mark the neighbor as visited and enqueue it
                visited[neighbor] = true;
                bfsQueue.push(neighbor);
            }
        }
    }

    cout << endl;
}

int main() {
    // Example usage
    Graph g(7);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 5);
    g.addEdge(2, 6);
    g.addEdge(3,4);
    int startVertex = 0;
    g.BFS(startVertex);

    return 0;
}
