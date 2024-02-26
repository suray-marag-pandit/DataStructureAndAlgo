#include <iostream>
#include<queue>
using namespace std;

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

node *insertIntoBST(node *&root, int data)
{

    if (root == NULL)
    {
        node *temp = new node(data);
        return temp;
    }

    if (data <= root->data)
    {
        root->left = insertIntoBST(root->left, data);
    }
    else
    {
        root->right = insertIntoBST(root->right, data);
    }

    return root;
}
void takeinput(node *&root)
{
    int data;
    cout << "Enter the data: ";
    cin >> data;

    while (data != -1)
    {
        root = insertIntoBST(root, data);
        cout << "Enter the data: ";
        cin >> data;
    }
}

void BFS(node * root){
    queue<node*> q;

    q.push(root);

    while(!q.empty()){

        node * temp =  q.front();
        q.pop();
        
        cout<<temp->data<<" ";

        if(temp->left){
            q.push(temp->left);
        }
        if(temp->right){
            q.push(temp->right);
        }
    }

}

bool search(node * root,int target){
    if(root==NULL){
        return false;
    }

    if(root->data==target)
        return true;

    if(target<root->data){
        return search(root->left,target);
    }
    else{
        return search(root->right,target);
    }

}

bool spaceOptimisedSearch(node * root,int target){
    node * temp = root;

    while(temp!=NULL){
        if(temp->data==target)
            return true;

        if(target<temp->data){
            temp=temp->left;
        }else{
            temp=temp->right;
        }
    }
    return false;
}
int main(int argc, char const *argv[])
{
    // 10 8 21 7 27 5 4 3 -1

    node * root = NULL;
    takeinput(root);
    BFS(root);

    // cout<<endl<<search(root,7);
    cout<<endl<<spaceOptimisedSearch(root,2);
    return 0;
}
