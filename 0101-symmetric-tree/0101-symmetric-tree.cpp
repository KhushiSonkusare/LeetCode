class Solution {
public:
    bool symmetric(TreeNode* p, TreeNode* q){
        if (p == nullptr && q == nullptr) return true;
        if (p == nullptr || q == nullptr) return false;

        return (p->val == q->val) &&
               symmetric(p->left, q->right) &&
               symmetric(p->right, q->left);
    }

    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        return symmetric(root->left, root->right);
    }
};
