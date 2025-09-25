class Solution {
public:
    vector<vector<int>> dp; 
    int n;

    int helper(vector<vector<int>>& triangle, int i, int j) {
        if (i == n - 1) return triangle[i][j];

        if (dp[i][j] != INT_MAX) return dp[i][j];

        int down = triangle[i][j] + helper(triangle, i + 1, j);
        int diag = triangle[i][j] + helper(triangle, i + 1, j + 1);

        return dp[i][j] = min(down, diag);
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        n = triangle.size();
        dp.assign(n, vector<int>(n, INT_MAX));
        return helper(triangle, 0, 0);
    }
};