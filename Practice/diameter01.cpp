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

node *buildTree(node *root)
{

    cout << "Enter the data: ";
    int data;
    cin >> data;

    if (data == -1)
        return NULL;

    root = new node(data);

    cout << "Enter the data for left: " << endl;
    root->left = buildTree(root->left);

    cout << "Enter the data for right: " << endl;
    root->right = buildTree(root->right);

    return root;
}

void bfs(node *root)
{
    queue<node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();

        if (temp == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";

            if (temp->left)
                q.push(temp->left);

            if (temp->right)
                q.push(temp->right);
        }
    }
}

int height(node * root){
    if(root==NULL){
        return 0;
    }

    int left = height(root->left);
    int right = height(root->right);

    return max(left,right)+1;
}

int diameter(node* root){
    if(root==NULL){
        return 0;
    }

    int left = diameter(root->left);
    int right = diameter(root->right);
    int op3 = height(root->left)+height(root->right)+1;

    return max(left,max(right,op3));
}

pair<int,int> diameterfast(node * root){
    if(root==NULL){
        pair<int,int> ans = make_pair(0,0);
        return ans;
    }

    pair<int,int> left = diameterfast(root->left);
    pair<int,int> right = diameterfast(root->right);

    int nodeCurve = left.second+right.second+1;

    pair<int,int> ans;
    ans.first = max(left.first,max(right.first,nodeCurve));
    ans.second = max(left.second,right.second)+1;
    return ans;
}
int main()
{
    node *root = NULL;
    root = buildTree(root);

    // 10 20 30 40 -1 -1 50 60 70 -1 -1 80 -1 -1 -1 10 -1 20 30 -1 -1 40 -1 50 -1 -1 60 -1 70 -1 -1
    bfs(root);

    cout<< endl<< diameter(root);
    cout << endl<< diameterfast(root).first;
    cout<<endl<<diameterfast(root).second;
    return 0;
}