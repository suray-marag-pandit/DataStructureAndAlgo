#include<iostream>
using namespace std;

class node {
    public:
    int data;
    node * right, * left;

    node(int data){
        this->data=data;
        this->right=NULL;
        this->left=NULL;
    }
};

bool valid(node * root,int min,int max){
    if(root==NULL)
        return true;

    if(root->data >= min && root->data <= max){
        bool l = valid(root->left,min,root->data-1);
        bool r = valid(root->right,root->data+1,max);
        return l && r;
    }
    
    return false;
}

int main(int argc, char const *argv[])
{
    node * root = new node(8);
    // root->right = new node(9);root->left = new node(2); //balance
    root->right = new node(9);root->left = new node(10); //not balance


    cout<<"valid bst: "<<valid(root,INT_MIN,INT_MAX)<<endl;


    return 0;
}
