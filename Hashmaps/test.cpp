#include <iostream>
#include <unordered_map>
using namespace std;

class node
{
public:
    int data;

    node(int data)
    {
        this->data = data;
    }
};

class key
{
public:
    string s;
    key(string s)
    {
        this->s = s;
    }
};

int main(int argc, char const *argv[])
{
    unordered_map<string, int> m;

    m["yel"] = 10;
    m["ol"] = 7;
    m["ola"] = 2;
    m["tum"] = 3;
    m["sts"] = 5;
    m["bob"] = 65;

    for (auto i : m)
    {
        cout << i.first << endl;
    }

    unordered_map<string, int>::iterator i =m.begin();

    while(i!=m.end()){
        cout<<i->first<<" "<<i->second<<endl;
        i++;
    }

        // pair<node,key>  p = make_pair(node(5),key( "hello"));
        return 0;
}
