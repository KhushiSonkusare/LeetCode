class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int ans = INT_MAX;

        vector<int>dp(n, INT_MAX);
        for (int j = 0; j < n; j++) {
            dp[j] = matrix[0][j];
        }

        
        for (int i = 0; i < n - 1; i++) {
            vector<int>temp(n,INT_MAX);
            for (int j = 0; j < n; j++) {
                if (j - 1 >= 0) 
                    temp[j - 1] = min(temp[j - 1], dp[j] + matrix[i + 1][j - 1]);

          
                temp[j] = min(temp[j], dp[j] + matrix[i + 1][j]);

                
                if (j + 1 < n) 
                    temp[j + 1] = min(temp[j + 1], dp[j] + matrix[i + 1][j + 1]);
            }
            dp = temp;
        }

        for (int j = 0; j < n; j++) {
            ans = min(ans, dp[j]);
        }

        return ans;
    }
};
