class Solution {
public:
    int maxProfit(vector<int>& nums) {
        int mini = nums[0], maxi = 0;
        for(int i = 0; i<nums.size(); i++){
            if(nums[i] > mini){
                maxi = max(maxi, nums[i] - mini);
            }else{
                mini = nums[i];
            }
        }

        return maxi;
    }
};