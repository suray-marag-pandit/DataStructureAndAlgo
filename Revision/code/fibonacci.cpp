#include<iostream>
using namespace std;

int fibonacci(int n,int a = 0, int b = 1){
    if(n==0)   return 0;
    if(n==1)    return 1;
    
    return fibonacci(n-1)+fibonacci(n-2);
}

int main(){
    // cout<<fibonacci(8);
    cout<<0<<" "<<1<<endl;
    fibonacci(8);
    return 0;
}