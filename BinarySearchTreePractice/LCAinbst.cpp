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

int lca(node * root,int a ,int b){
    if(root==NULL) return -1;

    if(root->data < a && root->data < b ) 
        return lca(root->right,a,b);
    else if(root->data > a && root->data > b)  
        return lca(root->left,a,b);
    return root->data;

}
int main(int argc, char const *argv[])
{
    // 10 8 21 7 27 5 4 3 -1

    node *root = NULL;
    takeinput(root);

    cout<<endl<<lca(root,21,4);

    return 0;
}
