class Solution {
public:
    int helper(string text1, string text2, int ind1, int ind2,
               vector<vector<int>> dp) {
        if (ind1 < 0 || ind2 < 0)
            return 0;
        if (dp[ind1][ind2] != -1)
            return dp[ind1][ind2];
        if (text1[ind1] == text2[ind2])
            dp[ind1][ind2] = 1 + helper(text1, text2, ind1 - 1, ind2 - 1, dp);
        else {
            dp[ind1][ind2] = max(helper(text1, text2, ind1 - 1, ind2, dp),
                                 helper(text1, text2, ind1, ind2 - 1, dp));
        }

        return dp[ind1][ind2];
    }

    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (text1[i - 1] == text2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        return dp[n][m];
    }
};
