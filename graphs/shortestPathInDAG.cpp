#include <iostream>
#include <stack>
#include <vector>
#include<list>
#include <unordered_map>
using namespace std;


void dfs(int N, vector<pair<int, int>> edges, stack<int> &ans, unordered_map<int, bool> &visited, unordered_map<int, list<int>> adj)
{
    visited[N] = true;

    for (auto i : adj[N])
    {
        if (!visited[i])
        {  
            dfs(i, edges, ans, visited, adj);
        }
    }

    ans.push(N); 
}

void topologicalSort(int N, vector<pair<int, int>> edges, stack<int> &ans)
{
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < edges.size(); i++)
    {
        adj[edges[i].first].push_back(edges[i].second);
    }

    unordered_map<int, bool> visited;
    for (int i = 0; i < N; i++)
    {
        if (!visited[i])
        {
            dfs(i, edges, ans, visited, adj);
        }
    }
}
int main(int argc, char const *argv[])
{
    int N = 6;
    vector<pair<int, int>> edges = {
        {1, 2},
        {1, 3},
        {2, 4},
        {3, 4},
        {4, 5},
        {4, 6},
        {5, 6},
    };

    stack<int> ans;

    topologicalSort(N, edges, ans);
    while(!ans.empty()){
        cout<<ans.top()<<" ";
        ans.pop();
    }

    return 0;
}
