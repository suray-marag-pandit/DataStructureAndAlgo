#include<iostream>
using namespace std;

void sayMyName(int n,string s[]){
    if(n==0)
        return;
    sayMyName(n/10,s);
    cout<<" "<<s[n%10];

}

int main(){
    string s[10]={"zero","one","two","three","four","five","six","seven","eight","nine"};
    int number;
    cin>>number;
    sayMyName(number,s);
    return 0;
}