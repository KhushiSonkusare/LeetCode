class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int, int> inMap;

        for (int i = 0; i < inorder.size(); i++) {
            inMap[inorder[i]] = i;
        }

        return build(inorder, 0, inorder.size() - 1,
                     postorder, 0, postorder.size() - 1, inMap);
    }

private:
    TreeNode* build(vector<int>& inorder, int inStart, int inEnd,
                    vector<int>& postorder, int postStart, int postEnd,
                    map<int, int>& inMap) {

        if (inStart > inEnd || postStart > postEnd) return nullptr;

        TreeNode* root = new TreeNode(postorder[postEnd]);
        int inPos = inMap[root->val];
        int numsLeft = inPos - inStart;

        root->left = build(inorder, inStart, inPos - 1,
                           postorder, postStart, postStart + numsLeft - 1, inMap);

        root->right = build(inorder, inPos + 1, inEnd,
                            postorder, postStart + numsLeft, postEnd - 1, inMap);

        return root;
    }
};
