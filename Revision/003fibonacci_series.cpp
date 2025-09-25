#include<iostream>
using namespace std;

int main(){
    int a = 0;
    int b = 1;

    cout<<"Fibonacci Series: ";
    cout<<a<<" "<<b<<" ";
    for(int i=0;i<10;i++){
        cout<< a + b <<" ";
      int next = a + b;  
        a = b;            
        b = next;
    }
    return 0;
}