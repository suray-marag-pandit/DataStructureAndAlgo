#include<iostream>
using namespace std;

class node {
    public:
    int data;
    node * next ;

    node(int data){
        this->data = data;
        this->next = NULL;
    }
};

class stack{
    node * pointer;
    int sizeS = 0;

    public:

    void push(int data){
        if(pointer==NULL){
            node * temp = new node(data);
            pointer = temp;
        }
        else{
            node * temp = new node(data);
            temp->next = pointer;
            pointer = temp;
        }
        sizeS++;
    }

    void pop(){
        if(pointer==NULL){
            cout<<"No element to delete"<<endl;
        }
        else{
        node * temp = pointer;
        pointer = pointer->next;
        delete temp;
        }
        sizeS--;
    }

    int size(){
        return this->sizeS;
    }
    void print(){
        node * temp = pointer;
        while(temp){
            cout<<temp->data<<" ";
            temp=temp->next;
        }cout<<endl;
    }

    int top(){
        return pointer->data;
    }
    stack(){
        this->pointer=NULL;
    }
};


int main(){
    
    stack * s = new stack();

    s->push(10);
    s->push(20);
    s->push(30);
    s->push(40);

    s->print();
    s->pop();
    s->print();
    cout<<s->size();
    cout<<endl<<s->top();
    return 0;
}