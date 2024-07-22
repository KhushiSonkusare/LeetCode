class Solution {
public:
    void sum(vector<int>& candidates, int target, vector<int>& ans,
             vector<vector<int>>& list, int startIndex) {
        if (target == 0) {
            list.push_back(ans);
            return;
        }
        if (target < 0) {
            return;
        }

        for (int i = startIndex; i < candidates.size(); i++) {
            if (i > startIndex && candidates[i] == candidates[i - 1]) continue; 
            ans.push_back(candidates[i]);
            sum(candidates, target - candidates[i], ans, list, i + 1);
            ans.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> list;
        vector<int> ans;
        sort(candidates.begin(), candidates.end()); 
        sum(candidates, target, ans, list, 0);
        return list;
    }
};
