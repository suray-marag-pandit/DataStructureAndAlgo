#include<iostream>
#include<queue>
using namespace std;


int main(int argc, char const *argv[])
{
    queue<string> q;

    q.push("hey");
    q.push("how");
    q.push("are");
    q.push("you");

    cout<<q.front();
    q.pop();
    cout<<q.empty();
    cout<<q.size();
    cout<<q.emplace();

    return 0;
}
