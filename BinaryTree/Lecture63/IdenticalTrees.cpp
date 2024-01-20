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

bool isIdentical(node * root1,node * root2){

    if(root1==NULL && root2==NULL)
        return true;

    if((root1==NULL && root2!=NULL) || (root1!=NULL && root2==NULL))
        return false;


    bool l = isIdentical(root1->left,root2->left);
    bool r = isIdentical(root1->right,root2->right);

    bool v = root1->data==root2->data;


    if(l && r && v){
        return true;
    }
    else{ 
        return false;
    }
}


int main(){
    node * root1 = NULL; 
    node * root2 = NULL; 

    root1 = build(root1);
    root2 = build(root2);

//   10 20 30 40 -1 -1 50 -1 -1 -1 60 70 -1 -1 80 -1 -1

    bool ans = isIdentical(root1,root2);

    cout<<endl<<ans;

    return 0;
}
