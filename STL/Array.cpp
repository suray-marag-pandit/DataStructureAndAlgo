#include <iostream>
#include <array>
using namespace std;

int main(int argc, char const *argv[])
{
    // array<type,size> variable_name = {elements};
    array<int, 4> a = {1, 2, 3, 4};

    int size = a.size();
    int element = a.at(2); // a.at(index) returns element;
    int first = a.front();
    int last = a.back();

    cout << size;
    return 0;
}
