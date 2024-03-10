#include <iostream>
#include <unordered_map>
#include <list>
#include<vector>
using namespace std;

bool checkCycleDFS(int n, unordered_map<int, bool> visited, unordered_map<int, bool> dfsVisited, unordered_map<int, list<int>> adj)
{
    visited[n] = true;
    dfsVisited[n] = true;

    for (auto neighbour : adj[n])
    {
        if (!visited[neighbour])
        {
            bool cycleDetected = checkCycleDFS(n, visited, dfsVisited, adj);
            if (cycleDetected)
            {
                return true;
            }
        }
        else if (visited[neighbour])
            return true;
    }

    dfsVisited[n] = false;
    return false;
}

bool detectCycleInDirectedGraph(int n, vector<pair<int, int>> &edges)
{
    // create adj list
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;

        adj[u].push_back(v);
    }

    // call dfs for all components
    unordered_map<int, bool> visited;
    unordered_map<int, bool> dfsVisited;
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            bool cycleFound = checkCycleDFS(i, visited, dfsVisited, adj);
            if (cycleFound)
                return true;
        }

        
    }return false;
}

int main(int argc, char const *argv[])
{
    //     int N = 6; // Number of nodes
    //     vector<pair<int, int>> edges = {{0, 4},
    //                                     {4, 2},
    //                                     {2, 3},
    //                                     {3, 5},
    //                                     {5, 1},
    //                                     {1, 4}};
    // Edges represented as pairs of (source, destination)
    int N = 3;
    vector<pair<int, int>> edges = {{1, 2},
                                    {2, 3},
                                    {3, 1}};

    bool ans = detectCycleInDirectedGraph(N, edges);
    cout << ans;

    return 0;
}
