#include<iostream>
using namespace std;

int distictWays(int n, int x){
    if(n==x)
        return 1;

    if(n>x)
        return 0;

    return distictWays(n+1,x)+distictWays(n+2,x);
}
int main(){
    int x = 2;
    cout<<distictWays(0,x) ;
    
    return 0;
}