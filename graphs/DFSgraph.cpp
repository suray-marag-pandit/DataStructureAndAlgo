#include <iostream>
#include <queue>
#include<stack>
using namespace std;

void DFS(int n, vector<pair<int, int>> edges)
{
    stack<int> s;
    vector<bool> visited(n, false);

    vector<int> adj[n];

    for (auto edge : edges)
    {
        adj[edge.first].push_back(edge.second);
        adj[edge.second].push_back(edge.first);
    }

    s.push(edges[0].first);

    while (!s.empty())
    {
        int node = s.top();
        s.pop();

        if (visited[node] != true)
        {
            cout << node << " ";
            visited[node] = true;

            for (int j = adj[node].size()-1; j >=0 ; j--)
            {
                s.push(adj[node][j]);
            }
        }
    }
}
int main(int argc, char const *argv[])
{
    int N = 6; // Number of nodes
    vector<pair<int, int>> edges = {{0, 4},
                                    {4, 2},
                                    {2, 3},
                                    {3, 5},
                                    {5, 1},
                                    {1, 4}};
    // Edges represented as pairs of (source, destination)

    DFS(N, edges);

    return 0;
}
