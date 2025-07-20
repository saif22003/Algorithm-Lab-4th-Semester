// Write a program to Implement dynamic programming
// method for all pair’s shortest path problem.

#include <iostream>
using namespace std;

const int INF = 1000000;  
const int MAX = 100;      

int main() {
    int n, m;  
    int dist[MAX][MAX];

    cout << "Enter number of vertices: ";
    cin >> n;

    // Initialize all distances
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j)
                dist[i][j] = 0;
            else
                dist[i][j] = INF;
        }
    }

    cout << "Enter number of edges: ";
    cin >> m;

    cout << "Enter edges in format: from to weight (1-based indexing)\n";
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--; 
        dist[u][v] = w;
    }

    // Floyd-Warshall Algorithm
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }

    // Print shortest distances
    cout << "\nShortest distances between every pair:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dist[i][j] == INF)
                cout << "INF\t";
            else
                cout << dist[i][j] << "\t";
        }
        cout << endl;
    }

    return 0;
}


// Result: 

// Enter number of vertices: 4
// Enter number of edges: 4
// Enter edges in format: from to weight (1-based indexing)
// 1 4  5
// 1 2 4
// 2 3 7
// 4 3 6

// Shortest distances between every pair:
// 0	4	11	5	
// INF	0	7	INF	
// INF	INF	0	INF	
// INF	INF	6	0