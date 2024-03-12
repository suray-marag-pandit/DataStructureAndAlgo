#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include<set>
#include <tuple>
using namespace std;


class adj{
    public:
    int a,b,w;
    adj(int a,int b,int w){
        this->a=a;
        this->b=b;
        this->w=w;
    }
};
void adjL(int a,int b,int w,vector<adj> &v){
    v.push_back(adj(a,b,w));
    v.push_back(adj(b,a,w));

}


int main(int argc, char const *argv[])
{
    vector<adj> v;
    adjL(0,1,5,v);
    adjL(0,2,8,v);
    adjL(1,2,9,v);
    adjL(1,3,2,v);
    adjL(3,2,6,v);
    adjL(0,2,8,v);

    for (auto i : v)
    {
        cout<<i.a<<"("<<i.b<<","<<i.w<<")"<<endl;
    }
    
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
