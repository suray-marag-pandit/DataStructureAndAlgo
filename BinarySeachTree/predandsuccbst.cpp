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

void inorder(node *root)
{
    if (root == NULL)
    {
        return;
    }

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

pair<int,int> preandsuc(node * root,int k ){
    
    int pre = -1;
    int suc = -1;
    node * temp = root;

    while(temp->data!=k){
        if(temp->data>k){
            suc=temp->data;
            temp=temp->left;
        }
        else{
            pre = temp->data;
            temp = temp->right;
        }
    }

    node * ltemp = temp->left;
    while(ltemp!=NULL){
        pre = ltemp->data; 
        ltemp = ltemp->right;
    }

    node * rtemp = temp->right;
    while(rtemp!=NULL){
        suc = rtemp->data;
        rtemp = rtemp->left;
    }

    return {pre,suc};

}

int main(int argc, char const *argv[])
{
    node *root = NULL;

    // 10 8 21 7 27 5 4 3 -1
    cout << "Enter the data";
    takeinput(root);
    inorder(root);

    cout<<endl;
    pair<int,int> ans = preandsuc(root,7);
    cout<<ans.first<<" "<<ans.second<<endl;

    return 0;
}