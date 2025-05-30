class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if (preorder.empty()) return nullptr;

        TreeNode* root = new TreeNode(preorder[0]);

        for (int i = 1; i < preorder.size(); i++) {
            TreeNode* curr = root;
            TreeNode* newNode = new TreeNode(preorder[i]);

            while (true) {
                if (preorder[i] < curr->val) {
                    if (curr->left == nullptr) {
                        curr->left = newNode;
                        break;
                    } else {
                        curr = curr->left;
                    }
                } else {
                    if (curr->right == nullptr) {
                        curr->right = newNode;
                        break;
                    } else {
                        curr = curr->right;
                    }
                }
            }
        }

        return root;
    }
};
