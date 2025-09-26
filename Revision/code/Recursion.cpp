#include<iostream>
using namespace std;

int factorial(int a){
    if(a==0){
        return 1;
    }
    return a* factorial(a-1);
}
int main(){
    cout<<factorial(5)<<endl;
    cout<<factorial(2)<<endl;
    cout<<factorial(4)<<endl;
    cout<<factorial(6)<<endl;
    return 0;
}