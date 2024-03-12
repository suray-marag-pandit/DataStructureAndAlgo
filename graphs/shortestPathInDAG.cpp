#include <iostream>
#include <stack>
#include <vector>
#include <list>
#include <unordered_map>
using namespace std;

class graph
{
public:
    unordered_map<int, list<pair<int, int>>> adj;

    void addEdge(int u, int v, int weight)
    {
        adj[u].push_back(make_pair(v, weight));
    }

    void print()
    {

        for (auto i : adj)
        {
            cout << i.first << " = ";
            for (auto j : adj[i.first])
            {
                cout << "(" << j.first << "," << j.second << "),";
            }
            cout << endl;
        }
    }
    

    
    void dfs(int N, stack<int> &ans, unordered_map<int,bool> visited)
    {
        visited[N] = true;

        for (auto i : adj[N])
        {
            if (!visited[i.first])
            {  
                dfs(i.first,ans, visited);
            }
        }

        ans.push(N); 
    }
};

int main(int argc, char const *argv[])
{
    graph g;

    g.addEdge(0, 1, 5);
    g.addEdge(0, 2, 3);
    g.addEdge(1, 2, 2);
    g.addEdge(1, 3, 6);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 4, 4);
    g.addEdge(2, 5, 2);
    g.addEdge(3, 4, -1);
    g.addEdge(4, 5, -2);

    g.print();

    int n = 6;
    unordered_map<int,bool> visited;
    stack<int> ans;
    for (int i = 0; i < n; i++)
    {
        if(visited[i])
            g.dfs(i,ans,visited);
    }
    

    return 0;
}
