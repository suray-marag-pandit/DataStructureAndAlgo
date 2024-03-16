#include <iostream>
using namespace std;

bool pallindrome(string s, int i) {
    //base case
    if (i >= s.length()/2)
        return true;

    if(s[i] == s[s.length() - 1 - i])
        return pallindrome(s, ++i);
    else
        return false;
}

int main() {
    string ans = "ugjvj";
    
    cout << pallindrome(ans, 0);
    return 0;
}
