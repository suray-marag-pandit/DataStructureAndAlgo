#include<iostream>
#include<stack>
using namespace std;


void middle(stack<int> &s,int n,int k){
    if(s.size()==n/2){
        s.push(k);
        return;
    }
    int temp = s.top();
    s.pop();
    middle(s,n,k);
    s.push(temp);

}

void last(stack<int> &s,int k){
    if(s.empty()){
        s.push(k);
        return;
    }
    int temp = s.top();
    s.pop();
    last(s,k);
    s.push(temp);

}
void reverse(stack<int> &s){
    if(s.empty()){
        return;
    }
    int temp = s.top();
    s.pop();

    reverse(s);
    last(s,temp);
    
}

void print(stack<int> s){
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
    
}

int main(){
    stack<int> s;

    s.push(50);
    s.push(40);
    s.push(30);
    s.push(20);
    s.push(10);
    middle(s,4,11);
    last(s,12);
    print(s);
    reverse(s);
    print(s);
    return 0;
}