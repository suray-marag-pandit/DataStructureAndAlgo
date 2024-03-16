#include<iostream>
using namespace std;

int exponent(int base,int power){
    if(power==0)
        return 1;

    if(power%2==0)
        return exponent(base,power/2)*exponent(base,power/2);
    else
        return base*exponent(base,power/2)*exponent(base,power/2);
}

int main(){ 
    int base = 3;
    int power = 10;
    cout<<exponent(base,power);
    return 0;
}