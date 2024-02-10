#include <iostream>
#include <queue>
#include <map>
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

node *build(node *root)
{
    cout << "Enter the data: ";
    int data;
    cin >> data;

    // to create leaf node children null
    if (data == -1)
        return NULL;

    root = new node(data);

    // to insert data in the left of the current postion
    // cout << "To the left of " << data << endl;
    root->left = build(root->left);

    // to insert data in the right of the current postion
    // cout << "To the right of " << data << endl;
    root->right = build(root->right);

    // to place node
    return root;
}

node *createmap(node *root, int target, map<node *, node *> &m)
{

    queue<node *> q;
    q.push(root);

    node *targetnode=NULL;

    while (!q.empty())
    {
        node *temp = q.front();
        q.pop(); 

        if (temp->left)
        {
            m[temp->left] = temp;
            q.push(temp->left);
        }

        if (temp->right)
        {
            m[temp->right] = temp;
            q.push(temp->right);
        }

        if (temp->data == target)
        {
            targetnode = temp;
        }
    }
    return targetnode;
}

int burn(node *target, map<node *, node* > &m)
{
    map<node *, bool> visited;
    queue<node *> travel;
    int time = 0;

    travel.push(target);
    visited[target] = true;

    while (!travel.empty())
    {

        node *temp = travel.front();
        travel.pop();

        bool flag= false;

        if (temp->left && visited[temp->left] == false)
        {
            visited[temp->left] = true;
            travel.push(temp->left);
            flag=true;
        }

        if (temp->right && visited[temp->right] == false)
        {
            visited[temp->right] = true;
            travel.push(temp->right);
            flag=true;
        }

        if (m[temp] && visited[m[temp]] == false)
        {
            visited[m[temp]] = true;
            travel.push(m[temp]);
            flag=true;
        }

        if (flag)
        {
            time++;
        }
    }

    return time;
}

int main()
{
    node *root = NULL;

    root = build(root);
    map<node*,node*> m;

    node * target = createmap(root,8,m);

    int time = burn(target,m);
    // 10 20 30 40 -1 -1 50 -1 -1 -1 60 70 -1 -1 80 -1 -1

    //1 2 4 -1 -1 5 7 -1 -1 8 -1 -1 3 -1 6 -1 9 -1 10 -1 -1
    cout<<time<<endl;
    return 0;
}