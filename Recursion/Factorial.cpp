#include<iostream>

using namespace std;


int factorial(int n){
    //base condition
    if(n==0){
        return 1;
    }

    return n* factorial(n-1);
}
int main(){
    //factorial
    cout<<factorial(5);
    return 0;
}