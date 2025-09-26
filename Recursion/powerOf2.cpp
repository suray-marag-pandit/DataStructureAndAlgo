//generate the power of 2 given the exponent number

#include<iostream>
using namespace std;

int powerOf2(int exponent){
    if(exponent == 0){
        return 1;
    }
    return 2 * powerOf2(exponent-1);
}

int main(){
    
    cout<<powerOf2(5)<<endl;
    cout<<powerOf2(10)<<endl;
    cout<<powerOf2(2)<<endl;
    return 0;
}