#include <iostream>
#include <stack>
#include<vector>
#include <list>
#include <unordered_map>
using namespace std;

bool isCycle(int n,int parent, unordered_map<int, list<int>>& adj, vector<pair<int, bool>> &visited)
{
    visited[n].second = true;
        for (auto neighbour : adj[n])
        {
            if (!visited[neighbour].second ){
                bool ans = isCycle(neighbour,n,adj,visited);
                if(ans)
                    return true;
            }
            else if (neighbour!=parent)
            {
                return true;
            }
        }
    return false;
}
bool cycleDetection(int n, vector<pair<int, int>> edges)
{

    unordered_map<int, list<int>> adj;

    for (int i = 0; i < edges.size(); i++)
    {
        adj[edges[i].first].push_back(edges[i].second);
        adj[edges[i].second].push_back(edges[i].first);
    }

    vector<pair<int, bool>> visited(n,{0,false});
    
    for (int i = 0; i < n; i++)
    {
        if (!visited[i].second)
        {
            bool ans = isCycle(n,-1, adj, visited);
            if (ans)
                return true;
        }
    }
    return false;
}
int main(int argc, char const *argv[])
{
    // int N = 6; // Number of nodes
    // vector<pair<int, int>> edges = {{0, 4},
    //                                 {4, 2},
    //                                 {2, 3},
    //                                 {3, 5},
    //                                 {5, 1},
    //                                 {1, 4}};
    // Edges represented as pairs of (source, destination)
    int N = 3;
    vector<pair<int, int>> edges = {{1, 2},
                                    {2, 3},
                                    {3, 1}};
                                
    bool ans = cycleDetection(N, edges);
    cout << ans;

    return 0;
}
