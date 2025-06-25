class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        
        
        int offset = sum;
        int maxRange = 2 * sum + 1;  

        vector<vector<int>> dp(n, vector<int>(maxRange, 0));
        
 
        dp[0][nums[0] + offset] += 1;
        dp[0][-nums[0] + offset] += 1;
        if (nums[0] == 0) dp[0][offset] = 2;  

        for (int i = 1; i < n; i++) {
            for (int s = -sum; s <= sum; s++) {
                int idx = s + offset;
                if (dp[i - 1][idx] > 0) {
                    dp[i][s + nums[i] + offset] += dp[i - 1][idx];
                    dp[i][s - nums[i] + offset] += dp[i - 1][idx];
                }
            }
        }

        if (target > sum || target < -sum) return 0;
        return dp[n - 1][target + offset];
    }
};
