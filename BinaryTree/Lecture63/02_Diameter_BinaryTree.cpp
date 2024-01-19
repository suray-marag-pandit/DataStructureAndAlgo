#include<iostream>
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


int height(node * root){
    if(root==NULL)
        return 0;

    int left = height(root->left);
    int right = height(root->right);

    return max(left,right)+1;
}


int diameter(node * root){
    if(root==NULL)
        return 0;
    
    int left = diameter(root->left);
    int right = diameter(root->right);
    int lheight = height(root->left)+height(root->right)+1;

    int ans = max(left,max(right,lheight));
    return ans;
}


pair<int,int> fastdiameter(node * root){

    if(root==NULL){
        pair<int,int> p = make_pair(0,0);
        return p;
    }

    pair<int,int> left = fastdiameter(root->left);
    pair<int,int> right = fastdiameter(root->right);

    int op1 = left.first;
    int op2 = right.first;
    int op3 = left.second +right.second+1;

    pair<int,int> ans;
    ans.first=max(op1,max(op2,op3));
    ans.second=max(left.second,right.second);

    return ans;

}

int main(){

    node * root =NULL;
    build(root);

    // 10 20 30 40 -1 -1 50 -1 -1 -1 60 70 -1 -1 80 -1 -1
    pair<int,int> ans = fastdiameter(root);

    cout<<ans.first;
    
    return 0;
}