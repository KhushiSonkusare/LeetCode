class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int i =0, j= nums.size()-1;
        while(i<=j){
            if(nums[i] == target && nums[j] == target){
                return {i,j};
            }else if(nums[i] == target){
                j--;
            }else if(nums[j] == target){
                i++;
            }else{
                i++;
                j--;
            }
        }
        return {-1,-1};
    }
};