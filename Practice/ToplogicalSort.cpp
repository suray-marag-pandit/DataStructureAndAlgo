#include<iostream>
#include<vector>
#include<list>
#include<stack>
#include<unordered_map>
using namespace std;


// Topological sorting for Directed Acyclic Graph (DAG) is a linear ordering of vertices such that for every directed edge u-v, vertex u comes before v in the ordering.

void dfs(int N,vector<pair<int, int>> edges, unordered_map<int,bool> &visited,unordered_map<int,list<int>> adj,stack<int> &s){
    visited[N]=true;

    for (auto i : adj[N])
    {
        if(!visited[i])
            dfs(i,edges,visited,adj,s);
    }
    
    s.push(N);


}
stack<int> Sort(int N,vector<pair<int, int>> edges){

    unordered_map<int,bool> visited;
    unordered_map<int,list<int>> adj;

    for (auto edge : edges)
    {
        adj[edge.first].push_back(edge.second);
    }


    stack<int> s;
    for (int i = 0; i < 6; i++)
    {
        if(!visited[i]){
            dfs(i,edges,visited,adj,s);
        }
    }
    
    return s;
    


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

    stack<int> s = Sort(N,edges);

    while (!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
    
    return 0;
}
