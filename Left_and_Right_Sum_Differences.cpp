class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        vector<int> lf(nums.size());
        vector<int> rs(nums.size());
        int sum = 0;
        for(int i = 0; i<nums.size(); i++){
            lf[i] = sum;
            sum+= nums[i];
        }
        sum =0;
        for(int i = nums.size()-1; i>=0; i--){
            
            rs[i]= sum;
            sum+=nums[i];
        }

        for(int i = 0; i<nums.size(); i++){
            nums[i] = abs(lf[i] - rs[i]);
        }
        return nums;
    }
};