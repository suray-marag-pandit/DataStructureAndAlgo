#include<iostream>
#include<vector>
using namespace std;

int fibo(int n, vector<int> &v){
    if(n == 0 || n == 1)
        return n;

    if(v[n] != -1)
        return v[n];

    v[n] = fibo(n - 1, v) + fibo(n - 2, v);
    return v[n];
}

int main(){
    //0 1 1 2 3 5 8 13 21 34 55
    int n = 3;
    vector<int> v(n + 1, -1);
    cout << fibo(n, v);
    return 0;
}
