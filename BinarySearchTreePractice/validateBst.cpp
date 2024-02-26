#include <iostream>
#include <queue>
#include <limits.h>
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
bool isValidBST(node *root, int minValue, int maxValue) {
    if (!root)
        return true;

    if (root->data <= minValue || root->data >= maxValue)
        return false;

    return isValidBST(root->left, minValue, root->data) && isValidBST(root->right, root->data, maxValue);
}


int main(int argc, char const *argv[])
{
    // 10 8 21 7 27 5 4 3 -1

    node *root = NULL;
    // takeinput(root);
    root  = new node(10);
    root->left = new node(11);
    root->right = new node(21);

    int l = INT_MIN;
    int r = INT_MAX;
    cout << isValidBST(root, l, r);
    return 0;
}
