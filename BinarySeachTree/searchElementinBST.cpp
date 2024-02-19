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

node *insert(node *&root, int data)
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

bool isPresent(node *root, int element)
{

    if (root == NULL)
    {
        return false;
    }
    if (root->data == element)
    {
        return true;
    }

    if (root->data < element)
        return isPresent(root->right, element);
    else
        return isPresent(root->left, element);
}

bool iteration(node * root,int data){
    if(root==NULL){
        return false;
    }

    node * temp =root;

    while(temp!=NULL){
        if(temp->data==data){
            return true;
        }
        if(temp->data > data){
            temp=temp->left;
        }else{
            temp=temp->right;
        }
    }

    return false;
}

int main(int argc, char const *argv[])
{
    node *root = NULL;

    // 10 8 21 7 27 5 4 3 -1
    cout << "Enter the data";
    takeinput(root);
    cout << "The element is: " << iteration(root, 5);
    cout << "The element is: " << isPresent(root, 11);

    return 0;
}