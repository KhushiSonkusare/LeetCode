class Solution {
public:
    long long total = 0;
    long long best = 0;
    const int MOD = 1e9 + 7;

    long long totalSum(TreeNode* root) {
        if (!root) return 0;
        return root->val + totalSum(root->left) + totalSum(root->right);
    }

    long long dfs(TreeNode* root) {
        if (!root) return 0;

        long long left = dfs(root->left);
        long long right = dfs(root->right);

        long long subSum = root->val + left + right;

        best = max(best, subSum * (total - subSum));

        return subSum;
    }

    int maxProduct(TreeNode* root) {
        total = totalSum(root);
        dfs(root);
        return best % MOD;
    }
};
