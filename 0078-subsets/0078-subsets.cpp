class Solution {
public:
    void helper(vector<vector<int>> &ans, vector<int> &curr, int ind, vector<int> nums){
        if(ind == nums.size()){
            ans.push_back(curr);
            return;
        }

        curr.push_back(nums[ind]);
        helper(ans, curr, ind+1, nums);
        curr.pop_back();
        helper(ans, curr, ind +1, nums);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;
        helper(ans, curr, 0, nums);
        return ans;
    }
};