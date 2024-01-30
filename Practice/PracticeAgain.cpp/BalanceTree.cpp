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

    cout<<"Enter the data";
    int data;
    cin>>data;

    if(data==-1){
        return NULL;
    }

    root = new node(data);

    cout<<"Enter the data for the left "<<data<<endl;
    root->left = build(root->left);

    cout<<"Enter the data for the right "<<data<<endl;
    root->right = build(root->right);

    return root;

}

void bfs(node * root){
    queue<node *> q;

    q.push(root);
    q.push(NULL);

    cout<<endl;
    while(!q.empty()){
        node * temp = q.front();
        q.pop();

        if(temp==NULL){
            cout<<endl;
            if(!q.empty()){ 
                q.push(NULL);
            }
        }
        else{
            cout<<temp->data<<" ";

            if(temp->left)
                q.push(temp->left);

            if(temp->right)
                q.push(temp->right);
        }
    }
}


pair<bool,int> checkBalance(node * root){
    if(root==NULL){
        pair<bool,int> ans = make_pair(true,0);
        return ans;
    }

    pair<bool,int> left = checkBalance(root->left);
    pair<bool,int> right = checkBalance(root->right);

    bool diff = abs(left.second-right.second)<=1;

    pair<bool,int> ans;

    if(left.first && right.first && diff){
        ans.second = max(left.second,right.second)+1;
        ans.first=true;
        return ans;
    }
    else{
        ans.first=false;
        ans.second=0;
        return ans;
    }
    
}

int main(int argc, char const *argv[])
{

    /* code */
    node * root = NULL;
    root = build(root);
    //10 20 30 40 -1 -1 50 -1 -1 -1 60 -1 70 -1 80 -1 -1
    bfs(root);

    /*
    balance tree
    1 10 5 -1 -1 -1 39 -1 -1
    */

    cout<<endl<<checkBalance(root).first<<endl;
    return 0;
}