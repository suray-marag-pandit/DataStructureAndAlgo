#include <iostream>
using namespace std;

void reverse(string &s, int i) {
    //base case
    if (i >= s.length()/2)
        return;

    swap(s[i++], s[s.length() - 1 - i]);
    reverse(s, i);
}

int main() {
    string ans = "why are you here";
    reverse(ans, 0);
    cout << ans;
    return 0;
}
