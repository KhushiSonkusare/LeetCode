class Solution {
public:
    void helper(vector<vector<int>>& ans, vector<int>& curr, int ind, int k, int n){
        if(k == 0){
            ans.push_back(curr);
            return;
        }
        for(int i = ind; i<=n; i++){
            curr.push_back(i);
            helper(ans, curr, i+1, k-1, n);
            curr.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> curr;
        helper(ans, curr, 1, k,n);
        return ans;
    }
};