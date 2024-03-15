#include<iostream>
using namespace std;

int exponent(int base,int power){
    if(power==0){
        return 1;
    }

    return base*exponent(base,power-1);
}

int main(){
    cout<<exponent(3,10);
    return 0;
}