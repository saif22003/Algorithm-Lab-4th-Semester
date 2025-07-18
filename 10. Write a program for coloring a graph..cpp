//Write a program for coloring a graph.

#include <iostream>
#include <vector>
using namespace std;

void colorGraph(int V, vector<vector<int>>& adj) {
    vector<int> result(V, -1);
    result[0] = 0;
    vector<bool> available(V, false);

    string colorName[] = {"Red", "Green", "Blue", "Yellow", "Orange", "Purple", "Cyan", "Pink"};

    for (int u = 1; u < V; u++) {
        for (int i : adj[u]) {
            if (result[i] != -1)
                available[result[i]] = true;
        }

        int color;
        for (color = 0; color < V; color++) {
            if (!available[color])
                break;
        }

        result[u] = color;

        for (int i : adj[u]) {
            if (result[i] != -1)
                available[result[i]] = false;
        }
    }

    // Print result with color names
    cout << "\nVertex\tColor" << endl;
    for (int i = 0; i < V; i++) {
        cout << i + 1 << "\t" << colorName[result[i]] << endl;
    }
}

int main() {
    int V, E;
    cout << "Enter number of vertices: ";
    cin >> V;
    cout << "Enter number of edges: ";
    cin >> E;

    vector<vector<int>> adj(V);

    cout << "Enter " << E << " edges (format: u v):" << endl;
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--; // 1-based input to 0-based index

        if (u < 0 || u >= V || v < 0 || v >= V) {
            cout << "Invalid edge: " << u + 1 << " " << v + 1 << " (ignored)" << endl;
            continue;
        }

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    colorGraph(V, adj);

    return 0;
}


//Result:

// Enter number of vertices: 4
// Enter number of edges: 4
// Enter 4 edges (format: u v):
// 1 2
// 1 4
// 4 3
// 2 3

// Vertex	Color
// 1	Red
// 2	Green
// 3	Red
// 4	Green