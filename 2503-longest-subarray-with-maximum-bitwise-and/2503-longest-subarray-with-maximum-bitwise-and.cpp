class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxi = 0;
        for(int i = 0; i<nums.size(); i++){
            maxi = max(maxi, nums[i]);
        }

        int j = 0, count = 0, mx = 0;
        while(j<nums.size()){
            if(nums[j] == maxi){
                count++;
            }else{
                count = 0;
            }
            j++;
            mx = max(mx, count);
        }
        return mx;
    }
};