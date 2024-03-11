#include <iostream>
#include <unordered_map>
#include <list>
#include <queue>
#include <vector>
using namespace std;

void Kahn(int N, vector<pair<int, int>> edges, unordered_map<int, list<int>> adj, vector<int> &indegree)
{
  queue<int> q;
  for (int i = 0; i < indegree.size(); i++)
  {
    if (indegree[i] == 0)
      q.push(i);
  }

  while (!q.empty()) {
    int temp = q.front();
    q.pop();
    cout << temp << " ";

    for(auto i : adj[temp]){
        indegree[i]--;
        if (indegree[i] == 0)
          q.push(i);
    }
  }
}

void Sort(int N, vector<pair<int, int>> edges)
{

  unordered_map<int, list<int>> adj;
  for (auto edge : edges)
  {
    adj[edge.first].push_back(edge.second);
  }

  vector<int> indegree(N);

  for (int i = 0; i < edges.size(); i++)
  {
    indegree[edges[i].second]++;
  }

  Kahn(N,edges,adj,indegree);
  // for (auto i : indegree)
  // {
  //   cout << i << endl;
  // }
}

int main(int argc, char const *argv[])
{
  int N = 6;
  vector<pair<int, int>> edges = {
      {2, 3},
      {3, 1},
      {4, 0},
      {4, 1},
      {5, 0},
      {5, 2},
  };

  Sort(N, edges);
  return 0;
}
