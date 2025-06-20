class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int num : nums) {
            sum += num;
        }

        if (sum % 2 == 1) {
            return false; 
        }

        int target = sum / 2;
        int n = nums.size();
        vector<vector<bool>> dp(n, vector<bool>(target + 1, false));

        for (int i = 0; i < n; i++) {
            dp[i][0] = true; 
        }

        if (nums[0] <= target)
            dp[0][nums[0]] = true;

        for (int i = 1; i < n; i++) {
            for (int t = 1; t <= target; t++) {
                bool notTaken = dp[i - 1][t];
                bool taken = false;
                if (nums[i] <= t)
                    taken = dp[i - 1][t - nums[i]];
                dp[i][t] = notTaken || taken;
            }
        }

        return dp[n - 1][target];
    }
};
