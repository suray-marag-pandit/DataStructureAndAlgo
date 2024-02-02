#include <iostream>
#include <queue>
using namespace std;

// creating node Structure
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

// to display the level order in one line
void LinearOutputBFS(node *root)
{

    // queue creation
    queue<node *> q;

    q.push(root);

    cout << endl
         << "The linear output for level order traversal: " << endl;
    while (!q.empty())
    {

        node *temp = q.front();
        q.pop();

        cout << temp->data << " ";

        // taking left child
        if (temp->left)
            q.push(temp->left);

        // taking right child
        if (temp->right)
            q.push(temp->right);
    }
}

// to display the level order in different line
void visualBFS(node *root)
{
    queue<node *> q;

    q.push(root);
    q.push(NULL);

    cout << endl;
    while (!q.empty())
    {

        node *temp = q.front();
        q.pop();

        if (temp == NULL)
        {
            cout << endl;
            if (!q.empty())
                q.push(NULL);
        }
        else
        {

            cout << temp->data << " ";

            // left child
            if (temp->left)
                q.push(temp->left);

            // right child
            if (temp->right)
                q.push(temp->right);
        }
    }
}

int pos(int inorder[], int target, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (inorder[i] == target)
            return i;
    }
    return -1;
}

node *inPostBuild(int inorder[], int postorder[], int &index, int instart, int inend, int size)
{
    if (index < 0 || instart > inend)
    {
        return NULL;
    }

    int temp = postorder[index--];
    node *root = new node(temp);
    int position = pos(inorder, temp, size);

    root->right = inPostBuild(inorder, postorder, index, position + 1, inend, size);
    root->left = inPostBuild(inorder, postorder, index, instart, position - 1, size);

    return root;
}

int main()
{

    node *root = NULL;
    int in[] = {3, 1, 4, 0, 5, 2};
    int pre[] = {0, 1, 3, 4, 2, 5};
    int post[] = {3, 4, 1, 5, 2, 0};
    int s = 5;

    root = inPostBuild(in, post, s, 0, 5, 6);

    // 10 20 30 40 -1 -1 50 -1 -1 -1 60 70 -1 -1 80 -1 -1
    LinearOutputBFS(root); // output 0 1 2 3 4 5

    visualBFS(root);
    return 0;
}