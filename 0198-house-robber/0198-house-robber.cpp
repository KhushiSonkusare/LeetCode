class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];

        vector<int> dp(n);  
        dp[0] = nums[0];

        for (int i = 1; i < n; i++) {
            int pick = nums[i];
            if (i - 2 >= 0) {
                pick += dp[i - 2];
            }
            int notpick = dp[i - 1];

            dp[i] = max(pick, notpick);
        }

        return dp[n - 1];
    }
};
