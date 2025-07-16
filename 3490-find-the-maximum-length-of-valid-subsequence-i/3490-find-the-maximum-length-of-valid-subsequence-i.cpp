class Solution {
public:
    vector<vector<int>> dp;

    int alternates(int ind, vector<int>& nums, int flag) {
        if (ind >= nums.size()) return 0;

        int fIndex = flag + 1;
        if (dp[ind][fIndex] != -1) return dp[ind][fIndex];

        int taken = 0;
        if (flag == -1 || nums[ind] % 2 != flag) {
            taken = 1 + alternates(ind + 1, nums, nums[ind] % 2);
        }

        int notTaken = alternates(ind + 1, nums, flag);

        return dp[ind][fIndex] = max(taken, notTaken);
    }

    int maximumLength(vector<int>& nums) {
        int n = nums.size();
        int even = 0, odd = 0;

        for (int num : nums) {
            if (num % 2 == 0) even++;
            else odd++;
        }

        dp.assign(n, vector<int>(3, -1));

        return max({alternates(0, nums, -1), even, odd});
    }
};
