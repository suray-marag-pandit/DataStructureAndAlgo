// using doubly linkedlist
#include <iostream>
#include <list>
using namespace std;

int main(int argc, char const *argv[])
{
    list<int> l;
    list<int> l2(l);
    list<int> l3(10,-1);

    l.push_back(10);
    l.push_front(2);

    // l.begin()
    l.empty();
    l.end();

    l.erase(l.begin(), l.end());
    l.size();

    return 0;
}
