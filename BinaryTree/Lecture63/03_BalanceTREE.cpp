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

// pair<bool,int> Diameter(node * root){
//     if(root==NULL){
//         pair<bool,int> p = make_pair(true,0);
//         return p;
//     }

//     pair<bool,int> left = Diameter(root->left);
//     pair<bool,int> right = Diameter(root->left);

//     bool leftans = left.first;
//     bool rightans = right.second;
//     bool diff = abs(left.second-right.second)<=1;


//     pair<bool,int> ans;
//     ans.second = max(left.second,right.second)+1;


//     if(leftans && rightans && diff){
//         ans.first = true;
//     }
//     else{
//         ans.first=false;
//     }

//     return ans;
// }

pair<bool,int> balance(node * root){
    if(root==NULL){
        pair<int,int> p = make_pair(true,0);
        return p;
    }

    pair<bool,int> Right = balance(root->right);
    pair<bool,int> Left = balance(root->left);

    pair<bool,int> ans ;

    //height
    ans.second = max(Left.second,Right.second)+1;
    bool l = Left.first;
    bool r = Right.first;
    bool curve = abs(Left.second-Right.second)<=1;
    
    if(l&&r&&curve)
        return {true,ans.second};
    else{
        return{false,ans.second};
    }
}








int main(){
    node * root = NULL;

    root = build(root);
    
    //balanced tree
    //1 10 5 -1 -1  -1 39 -1 -1

    //unbalance tree
    //1 10 5 -1 -1 -1 -1

    pair<bool,int> ans = balance(root);

    cout<<endl<<ans.first;

    return 0;
}
