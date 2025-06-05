class Solution {
public:
    void helper(vector<vector<int>>& comb, vector<int>& curr, int target, int ind, vector<int>& candidates) {
        if (target == 0) {
            comb.push_back(curr);
            return;
        }
        if (target < 0) {
            return;
        }

        for (int i = ind; i < candidates.size(); i++) {
            curr.push_back(candidates[i]);
            helper(comb, curr, target - candidates[i], i, candidates);
            curr.pop_back();  
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> comb;
        vector<int> curr;
        helper(comb, curr, target, 0, candidates);
        return comb;
    }
};
