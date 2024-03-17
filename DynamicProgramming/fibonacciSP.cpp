#include<iostream>
#include<vector>
using namespace std;

int fibo(int n){
    if(n==0)
        return 0;

    int a = 0;
    int b = 1;

    for(int i=2;i<=n;i++){
        int temp = a + b;
        a=b;
        b=temp;
    }
    return b;
}
int main(){
    int n = 6;
    cout<<fibo(n);
    return 0;
}