#include<iostream>
#include<queue>
using namespace std;


class node {
    public:
    int data;
    node * left;
    node * right;

    node(int data){
        this->data=data;
        this->left=NULL;
        this->right=NULL;

    }
};

void buildFromLevelOrder(node * &root){
    queue<node * > q;

    cout<<"Enter data for root: ";
    int rootdata;
    cin>>rootdata;

    root = new node(rootdata);

    q.push(root);

    while(!q.empty()){
        node * temp = q.front();
        q.pop();

        cout<<"Enter data for left "<<temp->data<<": ";
        int ldata;
        cin>>ldata;

        if(ldata!=-1){
            temp->left = new node(ldata);
            q.push(temp->left);
        }

        cout<<"Enter data in right "<<temp->data<<" : ";
        int rdata;
        cin>>rdata;
        
        if(rdata!=-1){
            temp->right = new node(rdata);
            q.push(temp->right);
        }
    
    }
}


void bfs(node * root){
    queue<node * > q;

    q.push(root);
    q.push(NULL);

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

int main(){

    node * root = NULL;

    buildFromLevelOrder(root);

    bfs(root);


    return 0;
}