class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(nums[0] < nums[1]){
            if(nums[1]<nums[2]){
                swap(nums[2],nums[1]);
            }else{
                swap(nums[1],nums[0]);
                swap(nums[1],nums[2]);
            }
        }else{
            if(nums[1]<nums[2]){
                swap(nums[2], nums[1]);
            }else{
                sort(nums.begin(),nums.end());
            }
        }
    }
};