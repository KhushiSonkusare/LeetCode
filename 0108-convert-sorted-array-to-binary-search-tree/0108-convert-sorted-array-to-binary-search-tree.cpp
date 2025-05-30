class Solution {
public:
    TreeNode* solve(vector<int>&nums,int l,int r){
        if(l>r) return NULL;

        int mid=l+(r-l)/2;
        TreeNode* newNode=new TreeNode(nums[mid]);

        newNode->left=solve(nums,l,mid-1);
        newNode->right=solve(nums,mid+1,r);

        return newNode;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return solve(nums,0,nums.size()-1);
    }
};