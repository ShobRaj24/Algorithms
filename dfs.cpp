#include <iostream>
#include <vector>
#include <stack>
#include <chrono>

using namespace std;
using namespace chrono;

class Graph {
public:
    Graph(int vertices);

    void addEdge(int v, int w);
    void DFS(int startVertex);

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

void Graph::DFS(int startVertex) {
    vector<bool> visited(vertices, false);
    stack<int> dfsStack;
    dfsStack.push(startVertex);
    visited[startVertex] = true;

    cout << "DFS traversal starting from vertex " << startVertex << ": ";

    while (!dfsStack.empty()) {
        int currentVertex = dfsStack.top();
        cout << currentVertex << " ";
        dfsStack.pop();

        for (const int &neighbor : adjacencyList[currentVertex]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                dfsStack.push(neighbor);
            }
        }
    }

    cout << endl;
}

int main() {
    Graph g(7);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 5);
    g.addEdge(2, 6);

    int startVertex = 0;

    // Measure execution time
    auto start = high_resolution_clock::now();
    
    g.DFS(startVertex);

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    cout << "Time taken by function: " << duration.count() << " microseconds" << endl;

    return 0;
}
