#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <stack>
#include <queue>
using namespace std;

void parentF(int N, vector<pair<int, int>> edges, vector<int> &parent, vector<bool> &visited, unordered_map<int, list<int>> adj)
{
    queue<int> track;
    track.push(N);
    visited[N] = true;

    while (!track.empty())
    {
        int temp = track.front();
        track.pop();
        for (auto i : adj[temp])
        {
            if (!visited[i])
            {
                visited[i] = true;
                parent[i] = temp;
                track.push(i);
            }
        }
    }
}

void path(int N, int s, int d, vector<pair<int, int>> edges)
{

    // adjency list
    unordered_map<int, list<int>> adj;
    for (auto edge : edges)
    {
        adj[edge.first].push_back(edge.second);
        adj[edge.second].push_back(edge.first);
    }

    // additional data structures
    vector<bool> visited(N + 1, false);
    vector<int> parent(N + 1);

    // first element
    parent[s] = -1;

    // call for parent implementation
    parentF(s, edges, parent, visited, adj);

    // ans output
    int i = d;
    while (i != s)
    {
        cout << i << "<-";
        i = parent[i];
    }
    cout << i;
}
int main(int argc, char const *argv[])
{
    int N = 8;
    vector<pair<int, int>> edges = {
        {1, 2},
        {1, 3},
        {1, 4},
        {4, 6},
        {6, 7},
        {7, 8},
        {3, 8},
        {2, 5},
        {5, 8},
    };

    path(N, 1, 8, edges);
    return 0;
}
