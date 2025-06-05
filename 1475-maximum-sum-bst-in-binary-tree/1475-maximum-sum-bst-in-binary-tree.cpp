class Solution {
public:
    int maxSum;

    struct res {
        bool isBST;
        int sum;
        int min;
        int max;
    };

    res helper(TreeNode* root) {
        if (root == nullptr) {
            
            return {true, 0, INT_MAX, INT_MIN};
        }

        res left = helper(root->left);
        res right = helper(root->right);

        if (left.isBST && right.isBST && root->val > left.max && root->val < right.min) {
            int currSum = root->val + left.sum + right.sum;
            maxSum = max(maxSum, currSum);
            return {
                true,
                currSum,
                min(root->val, left.min),
                max(root->val, right.max)
            };
        } else {
            return {false, 0, 0, 0};  // Not a BST
        }
    }

    int maxSumBST(TreeNode* root) {
        maxSum = 0;
        helper(root);
        return maxSum;
    }
};
