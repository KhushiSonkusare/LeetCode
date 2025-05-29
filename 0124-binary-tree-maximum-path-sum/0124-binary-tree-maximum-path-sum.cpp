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
class Solution {
public:

    int findmax(TreeNode* root, int &maxi){
        if(root == nullptr) return 0;

        int leftsum = max(0, findmax(root->left,maxi));
        int rightsum = max(0, findmax(root->right, maxi));

        maxi = max(maxi, leftsum+rightsum+ root->val);

        return max(leftsum, rightsum) + root->val;
    }
    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;

        findmax(root,maxi);

        return maxi;
    }
};