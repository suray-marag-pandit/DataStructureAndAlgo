#include <iostream>
#include <unordered_map>
using namespace std;

int main(int argc, char const *argv[])
{
    // creation
    unordered_map<string, int> m;

    // insertion
    pair<string, int> p = make_pair("hello ", 5);
    pair<string, int> p1("wow", 7);

    m.insert(p);
    m.insert(p1);
    m["helo"] = 10;

    // searching;
    cout << m["helo"] << endl;
    cout << m.at("wow") << endl;

    // size
    cout << m.size() << endl;
    // to check presence
    cout << m.count("killpill") << endl;

    // to erase
    m.erase("key_name");

    for(pair<string,int> i : m){
        cout<<i.first<<i.second<<endl;
    }
    return 0;
}
