class Solution {
public:
    void solve(vector<int>& nums, int idx, vector<int>& output, vector<vector<int>>& ans) {
        if (idx == nums.size()) {
            ans.push_back(output);
            return;
        }

        // Include current element
        output.push_back(nums[idx]);
        solve(nums, idx + 1, output, ans);
        output.pop_back();  // Backtrack

        // Skip duplicates
        while (idx + 1 < nums.size() && nums[idx] == nums[idx + 1]) {
            idx++;
        }

        // Exclude current element
        solve(nums, idx + 1, output, ans);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end()); // Sort to handle duplicates
        vector<int> output;
        vector<vector<int>> ans;
        solve(nums, 0, output, ans);
        return ans;
    }
};
