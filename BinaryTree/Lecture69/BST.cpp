#include <iostream>
#include <queue>
using namespace std;

class node
{

public:
    int data;
    node *left;
    node *right;

    node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};

node *insertInBst(node *&root, int data)
{
    if (root == NULL)
    {
        return new node(data);
    }

    if (data <= root->data)
    {
        root->left = insertInBst(root->left, data);
    }
    else
    {
        root->right = insertInBst(root->right, data);
    }

    return root;
}

node *build(node *&root)
{
    int data;
    cin >> data;

    while (data != -1)
    {
        root = insertInBst(root, data);
        cin>>data;
    }
    return root;
}

// bfs of tree
void bfs(node *root)
{
    // Base case
    if (root == NULL)
        return;

    queue<node *> q;
    q.push(root);
    q.push(NULL);

    /* One by one enqueue all nodes of tree */
    while (!q.empty())
    {
        node *curr_node = q.front();
       
        q.pop();

        if(curr_node==NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);  // Mark next level node as visited and print the next line after printing current line
            }
        }
        else{
             cout << curr_node->data << " ";
              if (curr_node->left!=NULL)
        {
            q.push(curr_node->left);
        }

        /* For a given point, enqueue right child only if it is not
        visited yet. Otherwise, print the node and remove it from queue.*/
        if (curr_node->right!=NULL)
        {
            q.push(curr_node->right);
        }
        }

        /* Enqueue left child and mark it as visited*/
      
    }
}

int main()
{
    node *root = NULL;

    build(root);
    printf("Breadth First Traversal of the constructed tree is \n");
    bfs(root);

    //10 8 21 7 27 5 4 3 -1

    return 0;
}