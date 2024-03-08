#include <iostream>
#include<queue>
using namespace std;


void BFS(int n,vector<pair<int, int>> edges){
    queue<int> q;
    vector<bool> visited(n,false);

    vector<int> adj[n];

    for(auto edge: edges){
        adj[edge.first].push_back(edge.second);
        adj[edge.second].push_back(edge.first);
    }

    q.push(0);

    while(!q.empty())
    {
        int node = q.front();
        q.pop();

        if(visited[node]!=true){
            cout<<node<<" ";
            visited[node]=true;

            for (int j = 0; j < adj[node].size(); j++)
            {
                q.push(adj[node][j]);
            }
        }
    }
}
int main(int argc, char const *argv[])
{
    int N = 5; // Number of nodes
    vector<pair<int, int>> edges = {{0, 3},
                                    {3, 1},
                                    {1, 2},
                                    {1, 4}};
                                     // Edges represented as pairs of (source, destination)

    BFS(N,edges);

    return 0;
}
