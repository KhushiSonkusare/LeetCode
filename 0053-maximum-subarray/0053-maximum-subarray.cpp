class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxel = INT_MIN;
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            maxel = max(sum, maxel);

            if (sum < 0)
                sum = 0;
            if(nums.size() == 1) maxel = nums[0];
        }

        return maxel;
    }
};