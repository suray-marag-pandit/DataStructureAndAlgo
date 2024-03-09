#include <iostream>
#include <queue>
#include <list>
#include <unordered_map>
using namespace std;

bool isCycle(int n, unordered_map<int, list<int>> adj, vector<pair<int, bool>> &visited)
{
    unordered_map<int, int> parent;

    parent[n] = -1;
    visited[n].second = true;

    queue<int> q;

    q.push(n);

    while (!q.empty())
    {
        int temp = q.front();
        q.pop();

        for (auto neighbour : adj[temp])
        {
            if (visited[neighbour].second == true && neighbour != parent[temp])
                return true;
            else if (!visited[neighbour].second)
            {
                q.push(neighbour);
                visited[neighbour].second = true;
                parent[neighbour] = temp;
            }
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
            bool ans = isCycle(n, adj, visited);
            if (ans)
                return true;
        }
    }
    return false;
}
int main(int argc, char const *argv[])
// {
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
                                
    bool ans = cycleDetection(N, edges);
    cout << ans;

    return 0;
}
