#include<iostream>
#include<stack>
using namespace std;


int main(int argc, char const *argv[])
{
    // stack<string> s;

    // s.push("hey");
    // s.push("how");
    // s.push("are");
    // s.push("you");

    // cout<<s.top();
    // s.pop();
    // cout<<s.empty();
    // cout<<s.size();
    // cout<<s.emplace();



    stack<int> s;

    int a = 5;
    s.emplace(a);
    a+=1;
    cout<<s.top();
    return 0;
}
