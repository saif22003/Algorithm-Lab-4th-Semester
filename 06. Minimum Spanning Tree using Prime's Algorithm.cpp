// Write a program to find the minimum cost spanning
// tree using prim’s algorithm.

#include <iostream>
#include <climits>
using namespace std;
#define MAX 100

int main() {
    int n, e;
    int cost[MAX][MAX];
    cout << "Enter number of vertices: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cost[i][j] = INT_MAX;
        }
    }
    cout << "Enter number of edges: ";
    cin >> e;
    cout << "Enter edges in format: source destination cost (e.g., 1 2 5)" << endl;
    for (int i = 0; i < e; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--; 
        v--;
        cost[u][v] = w;
        cost[v][u] = w; // undirected graph
    }

    int visited[MAX] = {0};
    visited[0] = 1; 
    int edgeCount = 0, minCost = 0;

    cout << "\nEdges in the Minimum Spanning Tree:\n";

    while (edgeCount < n - 1) {
        int minEdge = INT_MAX;
        int a = -1, b = -1;

        for (int i = 0; i < n; i++) {
            if (visited[i]) {
                for (int j = 0; j < n; j++) {
                    if (!visited[j] && cost[i][j] < minEdge) {
                        minEdge = cost[i][j];
                        a = i;
                        b = j;
                    }
                }
            }
        }

        if (a != -1 && b != -1) {
            cout << "Edge " << edgeCount + 1 << ": (" << a + 1 << " - " << b + 1 << ") cost = " << cost[a][b] << endl;
            visited[b] = 1;
            minCost += cost[a][b];
            edgeCount++;
        }
    }

    cout << "\nMinimum cost of the spanning tree = " << minCost << endl;

    return 0;
}

// Result:

// Enter number of vertices: 5
// Enter number of edges: 7
// Enter edges in format: source destination cost (e.g., 1 2 5)
// 1 2 5
// 1 4 2
// 1 3 3
// 2 3 4
// 4 3 2 
// 4 5 4
// 3 5 5

// Edges in the Minimum Spanning Tree:
// Edge 1: (1 - 4) cost = 2
// Edge 2: (4 - 3) cost = 2
// Edge 3: (3 - 2) cost = 4
// Edge 4: (4 - 5) cost = 4

// Minimum cost of the spanning tree = 12