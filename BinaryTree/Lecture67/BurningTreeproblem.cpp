#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node * left;
    node * right;

    node(int data){
        this->data  = data;
        this->left  =   NULL;
        this->right = NULL;
    }
};

node * build(node * root){
    cout<<"Enter the data";
    int data;
    cin>>data;

    if(data==-1){
        return NULL;
    }

    root = new node(data);

    cout<<"Enter the data for the left: ";
    root->left = build(root->left);

    cout<<"Enter the data for the right: ";
    root->right = build(root->right);

    return root;
}


int main(int argc, char const *argv[])
{
    //1 2 3 7 -1 -1 -1 4 -1 -1 -1 5 -1 6 -1 8 -1 -1

    node * root = NULL;
    root = build(root);

    return 0;
}
