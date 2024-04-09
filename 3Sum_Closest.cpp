class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        std::sort(nums.begin(), nums.end());
        int n = nums.size();
        int fsum = 0, diff = 10000;
        for (int i = 0; i < n - 2; ++i) {
            int left = i + 1;
            int right = n - 1;
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                int dif = abs(sum - target);
                if (dif<=diff) {
                    diff = dif;
                    fsum =sum;
                    ++left;
                    --right;
                } else if (sum < 0) {
                    ++left;
                } else {
                    --right;
                }
            }
        }
        
        return fsum;
    }
};