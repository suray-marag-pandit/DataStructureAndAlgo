#include <iostream>
#include <vector>
using namespace std;


string same(vector<string> &arr, int n)
{
    string ans;
    for (int i = 0; i < arr[0].length(); i++)
    {
        char ch = arr[0][i];
    

        bool match = false;

        for(int j = 1; j < arr.size(); j++) {
            if(arr[j][i]==ch && i < arr[j].size() )
                match = true;
            else{
                return ans;
            }
        }
        if(match==false)    
            return ans;
        else
            ans.push_back(ch);
    }
    return ans;
}


int main(int argc, char const *argv[])
{
    // vector<string> arr = {"code","codix","codeing","codehelp"};
    // vector<string> arr = {"apple", "app", "apricot"};
    // vector<string> arr = {"flower", "flow", "flight"};
    // vector<string> arr = {"dog", "racecar", "car"};
    vector<string> arr = {"prefix", "pre", "prelude"};

    string ans = same(arr,4);
    cout<<ans;

    return 0;
}
