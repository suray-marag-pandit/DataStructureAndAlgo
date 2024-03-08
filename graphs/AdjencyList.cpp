#include <iostream>
#include <vector>

using namespace std;


vector<vector<int>> printAdjacency(const int n, int m,vector<pair<int, int>> &edges) {
    vector<int> ans[n];
    for (int i = 0; i < m; i++) {
        int u = edges[i].first;
        int v = edges[i].second;
        ans[u].push_back(v);
        ans[v].push_back(u); // Added the missing semicolon
    }

    vector<vector<int>> adj(n);
    for (int i = 0; i < n; i++) {
        adj[i].push_back(i); // This is redundant
        for (int j = 0; j < ans[i].size(); j++) {
            adj[i].push_back(ans[i][j]); // Corrected the index from j to i
        }
    }


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < adj[i].size(); j++) {
            cout<<adj[i][j]<<" ";
        }cout<<endl;
    }
    return adj;
}

int main() {
    int N = 4;  // Number of nodes
    vector<pair<int, int>> edges = {{0, 1}, {1, 2}, {2, 3},{0,2}};  // Edges represented as pairs of (source, destination)

    vector<vector<int>> adjacencyList = printAdjacency(N,4, edges);
    // vector<vector<int>> adjacencyList = createAdjacencyList(N, edges);
    // printAdjacencyList(adjacencyList);

    return 0;
}
