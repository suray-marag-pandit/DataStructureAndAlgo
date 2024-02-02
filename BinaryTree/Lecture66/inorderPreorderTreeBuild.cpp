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

int index(int inorder[],int target,int size){
    for (int i = 0; i < size; i++)
    {
        if(inorder[i]==target)
            return i;
    }
    return -1;
}

node * inPreBuild(int inorder[],int preorder[],int &preindex,int instart,int inend,int size){
    if(preindex>=size || instart > inend){
        return NULL;
    }

    int temp = preorder[preindex++];
    node * root = new node(temp);
    int position = index(inorder,temp,size);

    root->left = inPreBuild(inorder,preorder,preindex,instart,position-1,size);
    root->right = inPreBuild(inorder,preorder,preindex,position+1,inend,size);

    return root;
}

int main()
{

    node *root = NULL;
    int in[] = {3,1,4,0,5,2};
    int pre[]={0,1,3,4,2,5};
    int s = 0;

    root = inPreBuild(in,pre,s,0,6,6);

    // 10 20 30 40 -1 -1 50 -1 -1 -1 60 70 -1 -1 80 -1 -1
    LinearOutputBFS(root);

    visualBFS(root);
    return 0;
}