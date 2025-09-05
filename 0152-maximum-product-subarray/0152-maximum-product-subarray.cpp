class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int ans = nums[0];
        int curMax = nums[0], curMin = nums[0];

        for (int i = 1; i < n; i++) {
            if (nums[i] < 0) swap(curMax, curMin); // flip if negative

            curMax = max(nums[i], nums[i] * curMax);
            curMin = min(nums[i], nums[i] * curMin);

            ans = max(ans, curMax);
        }

        return ans;
    }
};
