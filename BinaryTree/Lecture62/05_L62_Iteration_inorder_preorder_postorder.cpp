#include<iostream>
#include<stack>
using namespace std;

//creating node Structure
class node{

    public:
    int data;
    node * left;
    node * right;

    node(int data){
        this->data=data;
        this->left = NULL;
        this->right = NULL;
    }
};

node * build(node * root){
    cout<<"Enter the data: ";
    int data;
    cin>>data;

    //to create leaf node children null
    if(data==-1)
        return NULL;

    root = new node(data);

    //to insert data in the left of the current postion
    cout<<"To the left of "<<data<<endl;
    root->left = build(root->left);

    //to insert data in the right of the current postion
    cout<<"To the right of "<<data<<endl;
    root->right= build(root->right);

    //to place node
    return root;
    
}

void inorder(node * root){
    stack<node *> s;
    node * temp = root;

    cout<<endl<<endl;

    while(!s.empty() || temp!=NULL){

        while(temp){
            s.push(temp);
            temp=temp->left;
        }

        temp = s.top();
        s.pop();

        cout<< temp->data <<" ";
        temp = temp->right;
    }
}

void preorder(node * root){
    stack<node * > s;
    s.push(root);
    cout<<endl;

    while(!s.empty()){
        node * temp = s.top();
        cout<<temp->data<<" ";
        s.pop();

        if(temp->right)
            s.push(temp->right);

        if(temp->left)
            s.push(temp->left);
    }
}


void postorder(node * root){
    stack<node * > s;
    s.push(root);
    cout<<endl;

    while(!s.empty()){
        node * temp = s.top();
        cout<<temp->data<<" ";
        s.pop();

        if(temp->right)
            s.push(temp->right);

        if(temp->left)
            s.push(temp->left);
    }
}

int main(){
    node * root = NULL;

    //10 20 30 40 -1 -1 50 -1 -1 -1 60 70 -1 -1 80 -1 -1
    root = build(root);

    inorder(root);
    preorder(root);
    
    return 0;
}