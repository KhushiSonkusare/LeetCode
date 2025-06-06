class Solution {
public:
    void helper(vector<int>& candidates, int target, int index,
                vector<int>& curr, set<vector<int>>& result) {
        if (target == 0) {
            result.insert(curr);  // Use set to store only unique combinations
            return;
        }
        if (target < 0 || index >= candidates.size()) return;

        // Include current number
        curr.push_back(candidates[index]);
        helper(candidates, target - candidates[index], index + 1, curr, result);
        curr.pop_back();

        // Skip current number
        helper(candidates, target, index + 1, curr, result);
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());  // Sorting helps avoid duplicate issues
        set<vector<int>> result;
        vector<int> curr;
        helper(candidates, target, 0, curr, result);
        return vector<vector<int>>(result.begin(), result.end());  // Convert set to vector
    }
};
