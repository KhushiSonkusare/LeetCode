class Solution {
public:
    void generate(vector<int> &arr, int idx, vector<int> &subset, vector<vector<int>> &result) {
        result.push_back(subset);
        for (int i = idx; i < arr.size(); i++) {
            subset.push_back(arr[i]);
            generate(arr, i + 1, subset, result);
            subset.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& arr) {
        vector<int> subset;
        vector<vector<int>> result;
        generate(arr, 0, subset, result);
        return result;
    }
};