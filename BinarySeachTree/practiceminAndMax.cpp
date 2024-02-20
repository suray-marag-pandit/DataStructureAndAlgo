#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *left, *right;

    node(int data)
    {
        this->data = data;
        this->left = NULL, this->right = NULL;
    }
};


void preAndSuc(node * root,int &pre,int &suc,int key){
    if(root==NULL)
        return;

    if(root->data==key){

        if(root->left!=NULL){
            node * temp = root->left;
            while(temp->right){
                temp = temp->right;
            }
            pre = temp->data;
        }
        if(root->right!=NULL){
            node * temp = root->right;
            while(temp->left){
                temp = temp->left;
            }
            suc = temp->data;
        }
        return;
    }

    if(root->data<key){
        pre = root->data;
        preAndSuc(root->right,pre,suc,key);
    }
    else{
        suc = root->data;
        preAndSuc(root->left,pre,suc,key);
    }
}

node *insert(node *root, int data)
{
    if (root == NULL)
    {
        node *temp = new node(data);
        return temp;
    }

    if(data>=root->data){
        root->right = insert(root->right,data);
    }
    else{
        root->left = insert(root->left,data);
    }
    return root;
}
void takeintput(node *&root)
{
    cout << "Enter the data: ";
    int data;
    cin >> data;

    while (data != -1)
    {
        root = insert(root,data);
        cout << "Enter the data: ";
        cin >> data;
    }
}

void inorder(node * root){
    if(root==NULL)
        return;

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

int main(int argc, char const *argv[])
{
    node * root = NULL;

    // 10 8 21 7 27 5 4 3 -1
    takeintput(root);
    cout<<endl;
    inorder(root);

    int pre,suc,key=7;

    preAndSuc(root,pre,suc,key);
    cout<<endl<<"pre: "<<pre<<" "<<"suc: "<<suc;
    return 0;
}
