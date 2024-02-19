#include <iostream>

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

int min(node * root){
    node * temp = root;

    while(temp->left!=NULL){
        temp=temp->left;
    }

    return temp->data;
}

int max(node * root){
    node * temp = root;

    while(temp->right!=NULL){
        temp=temp->right;
    }

    return temp->data;
}
int main(int argc, char const *argv[])
{
    node *root = NULL;

    // 10 8 21 7 27 5 4 3 -1
    cout << "Enter the data: ";
    takeinput(root);

    cout<<"Min value: "<<min(root);
    cout<<endl<<"Max value: "<<max(root);


    return 0;
}