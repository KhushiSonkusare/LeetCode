class Solution {
public:
    int helper(vector<int> &nums, int goal){
        int left = 0, count = 0, sum = 0;

        for(int right = 0; right< nums.size(); right++){
            sum+= nums[right];

            while(left<= right && sum>goal){
                sum-= nums[left];
                left++;
            }

            count+= right - left +1;
        }
        return count;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return helper(nums, goal) - helper(nums, goal -1);
    }
};