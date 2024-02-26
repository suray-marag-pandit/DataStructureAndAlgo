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

void BFS(node *root)
{
    queue<node *> q;

    q.push(root);

    while (!q.empty())
    {

        node *temp = q.front();
        q.pop();

        cout << temp->data << " ";

        if (temp->left)
        {
            q.push(temp->left);
        }
        if (temp->right)
        {
            q.push(temp->right);
        }
    }
}

int maxInBST(node * root){
    if(root==NULL)
        return -1;
    node * temp =root;

    while (temp->right!=NULL){
        temp = temp->right;
    }

    return temp->data;
}

int minInBST(node * root){
    if(root==NULL)
        return -1;
    node * temp =root;

    while (temp->left!=NULL){
        temp = temp->left;
    }

    return temp->data;
}

int main(int argc, char const *argv[])
{
    // 10 8 21 7 27 5 4 3 2 30-1

    node *root = NULL;
    takeinput(root);

    cout << endl << maxInBST(root);
    cout << endl << minInBST(root);
    return 0;
}
