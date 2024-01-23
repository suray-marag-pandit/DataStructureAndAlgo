
#include<iostream>
#include<vector>
using namespace std;
// creating node Structure
class node
{

public:
    int data;
    node *left;
    node *right;

    node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

node *build(node *root)
{
    cout << "Enter the data: ";
    int data;
    cin >> data;

    // to create leaf node children null
    if (data == -1)
        return NULL;

    root = new node(data);

    // to insert data in the left of the current postion
    cout << "To the left of " << data << endl;
    root->left = build(root->left);

    // to insert data in the right of the current postion
    cout << "To the right of " << data << endl;
    root->right = build(root->right);

    // to place node
    return root;
}

void leftTraversal(node * root,vector<int> &ans){

    if((root==NULL) || (root->left==NULL&&root->right==NULL)){
            return;
    }

    ans.push_back(root->data);
    if(root->left)
        leftTraversal(root->left,ans);
    else
        leftTraversal(root->right,ans);
}

void leafnode(node * root,vector<int> &ans){
    if(root==NULL){
        return ;
    }

    if(root->left==NULL && root->right==NULL){
        ans.push_back(root->data);
    }

    leafnode(root->left,ans);
    leafnode(root->right,ans);
}

void rightTraversal(node * root, vector<int> &ans){

    if((root==NULL) || (root->left==NULL&&root->right==NULL)){
            return;
    }

    if(root->right)
        rightTraversal(root->right,ans);
    else
        rightTraversal(root->left,ans);

    ans.push_back(root->data);

}


int main(int argc, char const *argv[])
{
    node * root =NULL;
    root = build(root);

    // 10 20 30 40 -1 -1 50 -1 -1 -1 60 70 -1 -1 80 -1 -1
    vector<int> ans;
    ans.push_back(root->data);
    
    leftTraversal(root->left,ans);
    leafnode(root->left,ans);
    leafnode(root->right,ans);
    rightTraversal(root->right,ans);

    cout<<endl;
    for(auto i:ans){
        cout<<i<<" ";
    }

    return 0;
}