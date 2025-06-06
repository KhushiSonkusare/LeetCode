class Solution {
public:
    void helper(int start, int k, int n, vector<int>& curr, vector<vector<int>>& ans) {
        if (k == 0 && n == 0) {
            ans.push_back(curr);
            return;
        }

        if (k < 0 || n < 0) return;

        for (int i = start; i <= 9; ++i) {
            curr.push_back(i);
            helper(i + 1, k - 1, n - i, curr, ans); 
            curr.pop_back(); 
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> curr;
        helper(1, k, n, curr, ans);
        return ans;
    }
};
