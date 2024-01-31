#include<iostream>
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

vector<int> spiralTraversal(node *root){
    vector<int> k;
    if(root==NULL){
        return k;
    }


    queue<node *> q;
    q.push(root);
    bool LR = true;

    if(!q.empty()){
        
        int n = q.size();
        vector<int> ans;

        for(int i=0;i<n;i++){
            

        }


    }
}

int main(){
    node * root = NULL;

    root = build(root);
    
    //10 20 30 40 -1 -1 50 -1 -1 -1 60 70 -1 -1 80 -1 -1


    return 0;
}