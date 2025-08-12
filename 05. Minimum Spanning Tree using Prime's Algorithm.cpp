// Write a program to find the minimum cost spanning
// tree using prim’s algorithm.



#include <iostream>
#include <climits>
using namespace std;

int main() {
    int n, e;
    cout << "Enter number of vertices: ";
    cin >> n;

    int cost[100][100];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cost[i][j] = INT_MAX;

    cout << "Enter number of edges: ";
    cin >> e;

    cout << "Enter edges (u v w):\n";
    for (int i = 0; i < e; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--; // 1-based → 0-based
        cost[u][v] = w;
        cost[v][u] = w;
    }

    bool visited[100] = {false};
    visited[0] = true; // start from vertex 1
    int minCost = 0;

    cout << "\nEdges in MST:\n";
    for (int k = 0; k < n - 1; k++) {
        int u = -1, v = -1, minEdge = INT_MAX;

        // find minimum edge from visited set to unvisited set
        for (int i = 0; i < n; i++) {
            if (visited[i]) {
                for (int j = 0; j < n; j++) {
                    if (!visited[j] && cost[i][j] < minEdge) {
                        minEdge = cost[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }

        visited[v] = true;
        minCost += minEdge;
        cout << "(" << u + 1 << " - " << v + 1 << ") cost = " << minEdge << "\n";
    }

    cout << "\nMinimum cost = " << minCost << "\n";
    return 0;
}


// Result:

// Enter edges (u v w):
// 1 2 5
// 1 4 2
// 1 3 3
// 2 3 4
// 4 3 2
// 4 5 4
// 3 5 5

// Edges in MST:
// (1 - 4) cost = 2
// (4 - 3) cost = 2
// (3 - 2) cost = 4
// (4 - 5) cost = 4

// Minimum cost = 12