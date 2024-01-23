#include<iostream>
#include<queue>
#include<limits> // Include the <limits> header for numeric_limits
#include<cstdlib> // Include the <cstdlib> header for system("clear")

using namespace std;

class node {
public:
    int data;
    node* left;
    node* right;

    node(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

node* build(node* root) {
    // Prompt the user for input
    cout << "Enter the element (-1 to end the branch): ";
    int data;

    // Add error handling for invalid input
    if (!(cin >> data)) {
        cout << "Invalid input. Please enter an integer." << endl;
        // Handle the error, clear the input buffer
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return build(root);
    }

    // Base case: if -1 is entered, end the branch
    if (data == -1)
        return NULL;

    // Create a new node with the entered data
    root = new node(data);

    // Recursively build the left and right subtrees
    cout << "Enter the data for left ";
    root->left = build(root->left);

    cout << "Enter the data for right ";
    root->right = build(root->right);

    // Return the current root
    return root;
}

void bfs(node* root) {
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty()) {
        node* temp = q.front();
        q.pop();

        if (temp == NULL) {
            cout << endl;
            if (!q.empty()) {
                q.push(NULL);
            }
        }
        else {
            cout << temp->data << " ";

            if (temp->left)
                q.push(temp->left);

            if (temp->right)
                q.push(temp->right);
        }
    }
}

void inorder(node* root) {
    if (root == NULL)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void preorder(node* root) {
    if (root == NULL)
        return;

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(node* root) {
    if (root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

    node * buildFromBFS(node * root){
        cout<<"Enter the data ";
        int data;
        cin>>data;

        if(data==-1)
            return NULL;

        queue<node *> q;
        root = new node(data);

        q.push(root);

        while(!q.empty()){

            node * temp = q.front();
            q.pop();

            cout<<"Enter the left data "<<temp->data;
            int leftdata;
            cin>>leftdata;

            if(leftdata!=-1){
                temp->left = new node(leftdata);
                q.push(temp->left);
            }

            cout<<"Enter the right data "<<temp->data;
            int rightdata;
            cin>>rightdata;

            if(rightdata!=-1){
                temp->right = new node(rightdata);
                q.push(temp->right);
            }
        }

        return root;
}

int height(node * root){
    //base case
    if(root==NULL)
        return 0;

    int left = height(root->left);
    int right = height(root->right);

    return max(left,right)+1;
}

pair<int,int> Diameter(node * root){
    
    if(root==NULL){
        pair<int,int> p = make_pair(0,0);
        return p;
    }

    pair<int,int> Leftdiameter = Diameter(root->left);
    pair<int,int> rightdiameter = Diameter(root->right);

    //first for diameter and second is for height;
    pair<int,int> ans;
    //height;

    ans.second = max(Leftdiameter.second,rightdiameter.second)+1;

    int left = Leftdiameter.first;
    int second = rightdiameter.second;
    int curve =  Leftdiameter.second +rightdiameter.second+1;

    ans.first = max(left,max(second,curve));
    return ans;
}


pair<bool,int> checkbalance(node * root){

    if(root==NULL){
        pair<bool,int> p = make_pair(true,0);
        return p;
    }

    pair<bool,int> left = checkbalance(root->left);
    pair<bool,int> right = checkbalance(root->left);

    bool diff = abs(left.second-right.second)<=1;

    pair<bool,int> ans;
    ans.second = max(left.second,right.second)+1;

    if(left.first && right.first && ans.first){
        ans.first=true;
    }
    else{
        ans.first=false;
    }

    return ans;

}

pair<bool,int> checksum(node* root){
    
}
bool checkIdentical(node * root1,node * root2){
    if(root1==NULL && root2==NULL)
        return true;

    if((root1==NULL && root2!=NULL) || (root1!=NULL && root2==NULL))
        return false;

    bool left = checkIdentical(root1->left,root2->left);
    bool right = checkIdentical(root1->right,root2->right);

    if(left && right &&(root1->data==root2->data)){
        return true;
    }
    else{
        return false;
    }


}

pair<bool,int> checkSum(node * root){
    //base case
    if(root==NULL){
        pair<bool,int> p = make_pair(true,0);
        return p;
    }

    if(root->left==NULL && root->right==NULL){
        pair<bool,int> p = make_pair(true,root->data);
        return p;
    }

    pair<bool,int> left = checksum(root->left);
    pair<bool,int> right = checksum(root->right);

    pair<bool,int> ans;

    bool sum = root->data == (left.second+right.second)+1;
    
    if(left.first && right.first && sum){
        ans.first=true;
        ans.second=2*root->data;
    }
    else{
        ans.first=false;
    }
    return ans;
}

vector<int> spiralTraverse(node * root){
    
}

int main(int argc, char const* argv[]) {
    node* root = NULL;

    // Build the tree
    root = build(root);

// 10 20 30 40 -1 -1 50 -1 -1 -1 60 70 -1 -1 80 -1 -1
    // Handle the case where no tree is constructed
    if (!root) {
        cout << "No tree constructed. Exiting program." << endl;
        return 1; // Indicate an error
    }

    // Clear the screen before printing the results
    system("clear"); // For Linux/macOS
    // Or system("cls"); // For Windows

    // Print various traversals
    cout << "BFS Traversal:" << endl;
    bfs(root);
    cout << endl;

    cout << "Inorder Traversal:" << endl;
    inorder(root);
    cout << endl;

    cout << "Preorder Traversal:" << endl;
    preorder(root);
    cout << endl;

    cout << "Postorder Traversal:" << endl;
    postorder(root);

    cout<<endl<<"Height of Tree: "<<endl;
    cout<<height(root);

    cout<<endl<<"Diameter of the tree: "<<endl;
    cout<<Diameter(root).first;

    //balanced tree
    //1 10 5 -1 -1 -1 39 -1 -1

    cout<<endl<<"Is Tree Balance: "<<endl;
    cout<<checkbalance(root).first<<endl;

    node * root1 = NULL;
    node * root2 = NULL;

    build(root1);
    build(root2);

    cout<<endl<<"Is Tree Is Identical: "<<endl;
    cout<<checkIdentical(root1,root2);
    return 0; 
}