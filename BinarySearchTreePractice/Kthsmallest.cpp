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

int kth(node *root, int &i, int k)
{
    if (root == NULL)
        return -1;

    int l = kth(root->left, i, k);

    if (l != -1)
        return l;

    i++;
    
    if (i == k)
        return root->data;

    return kth(root->right, i, k);
}
int main(int argc, char const *argv[])
{
    // 10 8 21 7 27 5 4 3 -1

    node *root = NULL;
    takeinput(root);

    int i=0;
    cout<<endl<<kth(root,i,4);
    return 0;
}
