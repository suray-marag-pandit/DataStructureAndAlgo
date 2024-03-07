#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
    vector<int> v;
    // vector<type> variable_name(size,intital intialization element);
    v.push_back(10);
    v.push_back(10);
    v.push_back(10);
    v.push_back(10);
    v.push_back(10);
    v.push_back(10);
    v.push_back(10);
    v.push_back(10);
    cout << v.capacity() << endl; // how many memory vector allocate
    cout << v.size() << endl;     // how many elements vector have
    cout << v.at(4) << endl;
    cout << v.front();
    cout << v.back();
    v.pop_back();

    v.clear(); // removes elements but memory is still as before allocated to the vector;

    // starting iterator
    // v.begin();

    vector<int> a(15, -1);

    vector<int> copyVector(a);

    return 0;
}
