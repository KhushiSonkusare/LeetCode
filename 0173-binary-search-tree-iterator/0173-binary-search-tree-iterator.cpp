/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class BSTIterator {
private:
    stack<TreeNode*> s;

    void inorder(TreeNode* root) {
        while (root != nullptr) {
            s.push(root);
            root = root->left;
        }
    }

public:
    BSTIterator(TreeNode* root) {
        inorder(root);
    }

    int next() {
        TreeNode* node = s.top();
        s.pop();
        inorder(node->right);  // process right subtree
        return node->val;
    }

    bool hasNext() {
        return !s.empty();
    }
};
