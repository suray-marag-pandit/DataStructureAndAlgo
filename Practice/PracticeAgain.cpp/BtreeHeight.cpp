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

int height(node * root){
    if(root==NULL)
        return 0;

    int left = height(root->left);
    int right = height(root->right);

    return max(left,right)+1;
}

int main(int argc, char const *argv[])
{

    /* code */
    node * root = NULL;
    root = build(root);
    //10 20 30 40 -1 -1 50 -1 -1 -1 60 -1 70 -1 80 -1 -1
    bfs(root);

    cout<<endl<<height(root);
    return 0;
}
