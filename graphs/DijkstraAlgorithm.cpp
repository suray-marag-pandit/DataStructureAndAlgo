#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include<set>
#include <tuple>
using namespace std;


class adj{
    int a,b,w;
    adj(int a,int b,int w);
};



int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}





























































// void path(int N,int src, unordered_map<int, list<pair<int, int>>> adj)
// {
//     set<pair<int,int>> s;
//     s.insert(0,src);

// }

// void edge(int a, int b, int w, unordered_map<int, list<pair<int, int>>> &edges)
// {
//     edges[a].push_back(make_pair(b, w));
//     edges[b].push_back(make_pair(a, w));
// }

// int main(int argc, char const *argv[])
// {
//     int N = 4;

//     unordered_map<int, list<pair<int, int>>> edges;

//     edge(0, 2, 8, edges);
//     edge(0, 1, 5, edges);
//     edge(1, 2, 9, edges);
//     edge(1, 3, 2, edges);
//     edge(3, 2, 6, edges);

//     path(N, edges);
    
//     return 0;
// }
