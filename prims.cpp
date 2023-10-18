#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Structure to represent an edge
struct Edge {
    int destination;
    int weight;
};

// Function to find the minimum spanning tree using Prim's algorithm
void primMST(vector<vector<Edge>>& graph, int startVertex) {
    int numVertices = graph.size();

    // Priority queue to store edges with their weights
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // Vector to track the minimum weight for each vertex
    vector<int> minWeight(numVertices, INT_MAX);

    // Vector to track the parent vertex of each vertex in the MST
    vector<int> parent(numVertices, -1);

    // Vector to track whether a vertex is included in the MST or not
    vector<bool> inMST(numVertices, false);

    // Start with the given start vertex
    pq.push(make_pair(0, startVertex));
    minWeight[startVertex] = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        inMST[u] = true;

        for (const auto& edge : graph[u]) {
            int v = edge.destination;
            int weight = edge.weight;

            if (!inMST[v] && weight < minWeight[v]) {
                minWeight[v] = weight;
                parent[v] = u;
                pq.push(make_pair(minWeight[v], v));
            }
        }
    }

    // Print the minimum spanning tree
    cout << "Minimum Spanning Tree:" << endl;
    for (int i = 1; i < numVertices; ++i) {
        cout << parent[i] << " - " << i << endl;
    }
}

int main() {
    int numVertices, numEdges;
    cout << "Enter the number of vertices: ";
    cin >> numVertices;
    cout << "Enter the number of edges: ";
    cin >> numEdges;

    vector<vector<Edge>> graph(numVertices);

    cout << "Enter the edges (source destination weight):" << endl;
    for (int i = 0; i < numEdges; ++i) {
        int u, v, weight;
        cin >> u >> v >> weight;

        graph[u].push_back({v, weight});
        graph[v].push_back({u, weight});
    }

    int startVertex;
    cout << "Enter the starting vertex: ";
    cin >> startVertex;

    primMST(graph, startVertex);

    return 0;
}
