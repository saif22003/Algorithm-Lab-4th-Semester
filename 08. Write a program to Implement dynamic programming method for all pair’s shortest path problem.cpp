// Write a program to Implement dynamic programming
// method for all pair’s shortest path problem.

//Code From FARHAN

#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main() {
    int n, m;
   // cout << "Enter number of vertices: ";
    cin >> n;
    //cout << "Enter number of edges: ";
    cin >> m;

    // Initialize distance matrix
    vector<vector<int>> dist(n + 1, vector<int>(n + 1, INF));

    for (int i = 1; i <= n; ++i)
        dist[i][i] = 0;

  //  cout << "Enter edges in format (from to weight):\n";
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        dist[u][v] = w;
    }

    // Floyd-Warshall DP
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (dist[i][k] < INF && dist[k][j] < INF)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    // Output shortest distances
  cout << "\nShortest distances between every pair of vertices:\n";
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (dist[i][j] == INF)
                cout << "INF ";
            else
                cout << dist[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}