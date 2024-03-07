#include <iostream>
#include <queue>
using namespace std;

int main(int argc, char const *argv[])
{
    deque<int> q;

    q.push_back(10);
    q.push_back(20);
    q.push_back(30);
    q.push_front(20);
    q.push_front(40);
    q.push_front(50);
    q.push_front(60);

    // q.pop_front();
    for (auto &&i : q)
    {
        cout << i << " ";
    }

    cout << endl
         << q.at(1);
    cout << q.front();
    cout << q.back();

    cout << q.empty() << endl;

    q.erase(q.begin(),q.begin()+4);

      for (auto &&i : q)
    {
        cout << i << " ";
    }

        return 0;
}
