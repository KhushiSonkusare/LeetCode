class Solution {
public:
    void helper(vector<vector<int>>& ans, vector<int>& curr,
                vector<int>& candidates, int ind, int target) {
        if (target == 0) {
            ans.push_back(curr);
            return;
        }

        for (int i = ind; i < candidates.size(); i++) {
            if (i > ind && candidates[i] == candidates[i - 1])
                continue;

            if (candidates[i] > target)
                break;

            curr.push_back(candidates[i]);
            helper(ans, curr, candidates, i + 1, target - candidates[i]); 
            curr.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end()); 
        vector<vector<int>> ans;
        vector<int> curr;
        helper(ans, curr, candidates, 0, target);
        return ans;
    }
};
