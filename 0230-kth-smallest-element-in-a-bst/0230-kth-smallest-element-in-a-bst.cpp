class Solution {
public:
    void inorder(TreeNode* root, int& counter, int k, int& kthSmallest) {
        if (!root || counter >= k) return;

        inorder(root->left, counter, k, kthSmallest);

        counter++;
        if (counter == k) {
            kthSmallest = root->val;
            return;
        }

        inorder(root->right, counter, k, kthSmallest);
    }

    int kthSmallest(TreeNode* root, int k) {
        int counter = 0;
        int kthSmallestValue = 0;
        inorder(root, counter, k, kthSmallestValue);
        return kthSmallestValue;
    }
};
