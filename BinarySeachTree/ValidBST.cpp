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

bool valid(node *root,int min,int max)
{
    if (root == NULL)
        return true;

    if(root->data >=min && root->data<=max){
        bool left = valid(root->left,min,root->data-1);
        bool right = valid(root->right,root->data+1,max);
        return (left && right);
    }
    else 
        return false;
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
    // node *root = NULL;

    // // 10 8 21 7 27 5 4 3 -1
    // cout << "Enter the data: ";
    // takeinput(root);

    // cout << "Inorder traversal of the tree" << endl;
    // inorder(root);

    node * root = new node(5);
    root->right =new node(7); 
    root->left =  new node(8);

    cout << "validity: " << valid(root,INT_MIN,INT_MAX);
    return 0;
}