#include<iostream>
#include<stack>
#include<queue>
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

//to display the level order in different line
void reverseBFS(node * root){
    queue<node * >q;
    stack<int > s;

    q.push(root);

    cout<<endl;
    while(!q.empty()){

        node * temp = q.front();
        q.pop();
            s.push(temp->data);
            //left child
            if(temp->left)
                q.push(temp->left);
            //right child
            if(temp->right)
                q.push(temp->right);
    }

    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }cout<<endl;

}

int main(){
    node * root = NULL;

    root = build(root);
    
    //10 20 30 40 -1 -1 50 -1 -1 -1 60 70 -1 -1 80 -1 -1

    reverseBFS(root);
    return 0;
}