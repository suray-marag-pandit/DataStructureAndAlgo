#include <iostream>
#include <climits>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        // Helper function for inorder traversal
        return isValidBSTHelper(root, LONG_MIN, LONG_MAX);
    }

private:
    bool isValidBSTHelper(TreeNode* node, long min_val, long max_val) {
        if (node == nullptr)
            return true;
        if (node->val <= min_val || node->val >= max_val)
            return false;
        return isValidBSTHelper(node->left, min_val, node->val) && isValidBSTHelper(node->right, node->val, max_val);
    }
};

int main() {
    // Example usage
    TreeNode* root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(0);
    
    Solution sol;
    if (sol.isValidBST(root))
        cout << "The tree is a valid BST." << endl;
    else
        cout << "The tree is not a valid BST." << endl;
    
    // Clean up memory (not necessary for problem-solving, but good practice)
    delete root->left;
    delete root->right;
    delete root;
    
    return 0;
}
