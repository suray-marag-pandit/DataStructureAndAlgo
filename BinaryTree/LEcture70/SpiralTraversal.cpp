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
    cout << "To the left of " << data << endl;
    root->left = build(root->left);

    // to insert data in the right of the current postion
    cout << "To the right of " << data << endl;
    root->right = build(root->right);

    // to place node
    return root;
}

vector<int> Zig(node *root)
{
    vector<int> result;
    if (root == NULL)
        return result;


    queue<node *> q;
    q.push(root);

    bool flag = true;

    while (!q.empty())
    {
        int size = q.size();
        vector<int> ans(size);

        for (int i = 0; i < size; i++)
        {
            node *temp = q.front();
            q.pop();

            
            int index = flag ? i : size - i - 1;
            ans[index] = temp->data;


            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
        flag = !flag;
        for (auto i : ans)
        {
            result.push_back(i);
        }
    }
    return result;
}

int main()
{
    node *root = NULL;

    root = build(root);

    // 10 20 30 40 -1 -1 50 -1 -1 -1 60 70 -1 -1 80 -1 -1
    return 0;
}