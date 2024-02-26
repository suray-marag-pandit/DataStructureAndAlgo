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

int min(node *root)
{
    if (root == NULL)
        return -1;
    node *temp = root;

    while (temp->left != NULL)
    {
        temp = temp->left;
    }

    return temp->data;
}

node *deletion(node *&root, int target)
{
    // base case
    if (root == NULL)
        return root;

    if (target == root->data)
    {
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }

        if (root->left != NULL && root->right == NULL)
        {
            node *temp = root->left;
            delete root;
            return temp;
        }
        if (root->right != NULL && root->left == NULL)
        {
            node *temp = root->right;
            delete root;
            return temp;
        }

        if (root->left != NULL && root->right != NULL)
        {
            int mini = min(root->right);
            root->data = mini;
            root->right = deletion(root->right, mini);
            return root;
        }
    }

    else if (target < root->data)
        root->left = deletion(root->left, target);
    else
        root->right = deletion(root->right, target);

    return root;
}

int main(int argc, char const *argv[])
{
    // 10 8 21 7 27 5 4 3 -1

    node *root = NULL;
    takeinput(root);
    BFS(root);
    root = deletion(root,27);
    BFS(root);
    return 0;
}
