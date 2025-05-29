class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> inMap;
        for (int i = 0; i < inorder.size(); i++) {
            inMap[inorder[i]] = i;
        }

        return build(inorder, 0, inorder.size() - 1, preorder, 0, preorder.size() - 1, inMap);
    }

private:
    TreeNode* build(vector<int>& inorder, int inStart, int inEnd,
                    vector<int>& preorder, int preStart, int preEnd,
                    unordered_map<int, int>& inMap) {

        if (preStart > preEnd || inStart > inEnd) {
            return nullptr;
        }

        TreeNode* root = new TreeNode(preorder[preStart]);
        int posIn = inMap[root->val];
        int numsLeft = posIn - inStart;

        root->left = build(inorder, inStart, posIn - 1,
                           preorder, preStart + 1, preStart + numsLeft, inMap);
        root->right = build(inorder, posIn + 1, inEnd,
                            preorder, preStart + numsLeft + 1, preEnd, inMap);

        return root;
    }
};
