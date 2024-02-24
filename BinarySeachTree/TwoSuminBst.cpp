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

node *insert(node *root, int data)
{

    if (root == NULL)
    {

        node *temp = new node(data);
        return temp;
    }

    if (data >= root->data)
    {

        root->right = insert(root->right, data);
    }
    else
    {

        root->left = insert(root->left, data);
    }

    return root;
}

void takeinput(node *&root)
{

    int data;
    cin >> data;

    while (data != -1)
    {
        root = insert(root, data);
        cin >> data;
    }
}

void inorder(node *root,vector<int> &arr)
{
    if (root == NULL)
    {
        return;
    }

    inorder(root->left,arr);
    arr.push_back(root->data);
    inorder(root->right,arr);
}



int main(int argc, char const *argv[])
{
    node *root = NULL;

    // 10 8 21 7 27 5 4 3 -1
    cout << "Enter the data";
    takeinput(root);

    cout << "Inorder traversal of the tree" << endl;
    vector<int> arr;
    inorder(root,arr);

    int sum = 7;
    for(int i=0,j=arr.size();i<j;){
        int temp = arr[i]+arr[j];
        if(temp==sum){
            cout<<arr[i]<<" "<<arr[j]<<endl;
            break;
        }
        else if(temp>sum){
            j--;
        }
        else{
            i++;
        }
    }
    

    return 0;
}