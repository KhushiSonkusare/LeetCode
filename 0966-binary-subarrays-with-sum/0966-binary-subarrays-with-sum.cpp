class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return atmostK(nums, goal) - atmostK(nums, goal - 1);
    }
private:
    int atmostK(vector<int>& nums, int goal) {
        int i = 0;
        int j = 0;
        int sum = 0;
        int ans = 0;

        while (i < nums.size()) {
            sum += nums[i];

            while (j <= i && sum > goal) {
                sum -= nums[j];
                j++;
            }
            ans += i - j + 1;
            i++;
        }
        return ans;
    }
};