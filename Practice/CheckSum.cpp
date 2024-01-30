#include<iostream>
#include<queue>
using namespace std;

class node{
    public:
    int data;
    node * left, * right;

    node(int data){
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }
};

node * build(node * root){

    // cout<<"Enter the data";
    int data;
    cin>>data;

    if(data==-1){
        return NULL;
    }

    root = new node(data);

    // cout<<"Enter the data for the left "<<data<<endl;
    root->left = build(root->left);

    // cout<<"Enter the data for the right "<<data<<endl;
    root->right = build(root->right);

    return root;

}

pair<bool,int> checkSum(node * root){
    pair<bool,int> ans;


    if(root==NULL){
        ans.first=true;
        ans.second=0;
        return ans;
    }

    if(root->left==NULL && root->right==NULL){
        ans.first=true;
        ans.second=root->data;
        return ans;
    }

    pair<bool,int> left = checkSum(root->left);
    pair<bool,int> right = checkSum(root->right);

    bool check = (left.second +right.second) == root->data;

    if(left.first && right.first && check){
        ans.first=true;
        ans.second = 2*(root->data);
    }
    else{
        ans.first=false;
        ans.second=0;
    }
    return ans;
}

int main(int argc, char const *argv[])
{

    /* code */
    node * root = NULL;
    root = build(root);
    //10 20 30 40 -1 -1 50 -1 -1 -1 60 -1 70 -1 80 -1 -1

    //3 1 -1 -1 2 -1 -1

    cout<<checkSum(root).first;
    return 0;
}