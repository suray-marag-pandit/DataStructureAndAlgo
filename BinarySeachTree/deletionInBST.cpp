#include <iostream>
#include <queue>
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

node *insert(node *root, int data)
{

    if (root == NULL)
    {

        node *temp = new node(data);
        return temp;
    }

    if (data >= root->data)
    {

        root->right = insert(root->right, data);
    }
    else
    {

        root->left = insert(root->left, data);
    }

    return root;
}

void takeinput(node *&root)
{

    int data;
    cin >> data;

    while (data != -1)
    {
        root = insert(root, data);
        cin >> data;
    }
}

node * min(node * root){
    node * temp = root->right;
    while(temp->left!=NULL)
            temp=temp->left;

    return temp;

}
node * deletion(node * root,int data){

    if(root==NULL){
        return NULL;
    }

    if(root->data==data){
        //0 child
        if(root->left==NULL && root->right==NULL){
            delete root;
            return NULL;
        }

        //1 child
        if(root->left!=NULL && root->right==NULL){
            node * temp = root->left;
            delete root;
            return temp;
        }
        if(root->left==NULL && root->right!=NULL){
            node * temp = root->right;
            delete root;
            return temp;
        }

        //both child
        if(root->left!=NULL && root->right!=NULL){
            int mini = min(root->right)->data;
            root->data = mini;
            root->right = deletion(root,mini);
            return root;
        }

    }
    else{
        if(root->data>data){
            root->left = deletion(root->left,data);
            return root;
            }
        else{
            root->right = deletion(root->right,data);
            return root;
        }
    }
}
void inorder(node *root)
{
    if (root == NULL)
    {
        return;
    }

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
int main(int argc, char const *argv[])
{
    node *root = NULL;

    // 10 8 21 7 27 5 4 3 -1
    cout << "Enter the data";
    takeinput(root);

    inorder(root);
    cout << "Inorder traversal of the tree" << endl;

    root = deletion(root,7);

    inorder(root);
    return 0;
}