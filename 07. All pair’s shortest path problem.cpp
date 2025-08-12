// Write a program to Implement dynamic programming
// method for all pair’s shortest path problem.

#include<iostream>
#include<vector>
using namespace std;

const int INF = 1000;

void floydWarshall(vector<vector<int>>& graph, int v) {
  vector<vector<int>> cost = graph;

  for(int k = 0; k < v; k++) {
    for(int i = 0; i < v; i++) {
      for(int j = 0; j < v; j++) {
    cost[i][j] = min(cost[i][k] + cost[k][j], cost[i][j]);
      }
    }
  }

  cout << endl << "All shortest paths: " << endl;
  for(int i = 0; i < v; i++) {
    for(int j = 0; j < v; j++) {
      if(cost[i][j] == INF)
        cout << "INF ";
      else
        cout << cost[i][j] << "  ";
    }
    cout << endl;
  }
  cout << endl;
}


int main() {
int v;
cout<<"Enter number of vertices: ";
cin>>v;
vector<vector<int>> graph(v, vector<int>(v));
cout<<"Enter adjancency matrix: "<<endl;
for(int i=0; i<v; i++) {
    for(int j=0; j<v; j++){
        cin>>graph[i][j];
    }
}

 floydWarshall(graph,v);
return 0;
}


// Result: 

// Enter number of vertices: 3
// Enter adjancency matrix: 
// 0 1000 2
// 2 0 1
// 3 1000 0

// All shortest paths: 
// 0  INF 2  
// 2  0  1  
// 3  INF 0  