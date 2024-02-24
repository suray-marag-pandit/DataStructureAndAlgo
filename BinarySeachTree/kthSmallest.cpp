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

int kth(node *root, int &i, int k)
{
    if (root == NULL)
        return -1;

    int l = kth(root->left, i, k);

    if (l != -1)
    {
        return l;
    }

    i++;
    if (i == k)
        return root->data;

    return kth(root->right, i, k);
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

    int i =0;
    inorder(root);
    cout << "kth smallest element: " << kth(root,i,6) << endl;

    return 0;
}