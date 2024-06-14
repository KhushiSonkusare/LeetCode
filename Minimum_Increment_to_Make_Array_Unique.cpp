class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        if(nums.empty()) return 0;

        sort(nums.begin(), nums.end());
        int prev = nums[0];
        int sum = 0;

        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] <= prev) {
                sum += (prev - nums[i]) + 1;
                nums[i] = prev + 1;
            }
            prev = nums[i];
        }

        return sum;
    }
};