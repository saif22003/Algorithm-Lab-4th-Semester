// Write a program to find the single source path.

#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

vector<pair<int, int>> adjList[1000];

vector<int> dijkstra(int source, vector<pair<int, int>> adjList[], int numVertices) {
    vector<int> distance(numVertices + 1, INT_MAX);  // Stores shortest distances
    distance[source] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, source});

    while (!pq.empty()) {
        int currentDist = pq.top().first;
        int currentNode = pq.top().second;
        pq.pop();

        for (auto neighbor : adjList[currentNode]) {
            int nextNode = neighbor.first;
            int weight = neighbor.second;

            if (distance[currentNode] + weight < distance[nextNode]) {
                distance[nextNode] = distance[currentNode] + weight;
                pq.push({distance[nextNode], nextNode});
            }
        }
    }

    return distance;
}

int main() {
    int vertices, edges;
    cout << "Enter the number of vertices: ";
    cin >> vertices;

    cout << "Enter the number of edges: ";
    cin >> edges;

    cout << "Enter each edge in the format: vertex1 vertex2 weight" << endl;
    for (int i = 0; i < edges; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adjList[u].push_back({v, w});
        adjList[v].push_back({u, w}); // For undirected graph
    }

    int startVertex;
    cout << "Enter the starting vertex: ";
    cin >> startVertex;

    vector<int> shortestDistances = dijkstra(startVertex, adjList, vertices);

    cout << "\nShortest distances from vertex " << startVertex << ":" << endl;
    for (int i = 1; i <= vertices; ++i) {
        cout << "To vertex " << i << " -> Distance: ";
        if (shortestDistances[i] == INT_MAX) {
            cout << "Unreachable" << endl;
        } else {
            cout << shortestDistances[i] << endl;
        }
    }

    return 0;
}

//Result :

// Enter the number of edges: 5
// Enter each edge in the format: vertex1 vertex2 weight
// 1 2 3
// 1 3 4
// 2 4 5
// 2 3 3
// 3 4 2
// Enter the starting vertex: 1

// Shortest distances from vertex 1:
// To vertex 1 -> Distance: 0
// To vertex 2 -> Distance: 3
// To vertex 3 -> Distance: 4
// To vertex 4 -> Distance: 6