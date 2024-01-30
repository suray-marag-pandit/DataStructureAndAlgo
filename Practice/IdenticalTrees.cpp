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

bool checkIndentical(node * root1 , node * root2){
    if(root1==NULL && root2==NULL){
        return true;
    }

    if((root1==NULL && root2!=NULL) || (root1!=NULL && root2==NULL)){
        return false;
    }

    bool left = checkIndentical(root1->left,root2->left);
    bool right = checkIndentical(root1->right,root2->right);

    bool value = (root1->data==root2->data);
    if(left && right && value){
        return true;
    }
    else{
        return false;
    }
}

int main(int argc, char const *argv[])
{

    /* code */
    node * root1 = NULL;
    node * root2 = NULL;
    root1 = build(root1);
    root2 = build(root2);
    //10 20 30 40 -1 -1 50 -1 -1 -1 60 -1 70 -1 80 -1 -1
    
    cout<< checkIndentical(root1,root2);
    return 0;
}