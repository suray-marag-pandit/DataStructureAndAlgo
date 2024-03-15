#include<iostream>
using namespace std;

void counting(int n){
    //base case
    if(n==0)
        return;
    counting(n-1);
    cout<<n<<" ";
}

int main(){
    counting(100);
    return 0;
}