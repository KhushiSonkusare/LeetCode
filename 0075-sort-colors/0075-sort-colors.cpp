class Solution {
public:
    void sortColors(vector<int>& nums) {
        int ones = 0, zeroes = 0;

        for(int num:nums){
            if(num == 0) zeroes++;
            if(num == 1) ones++;
        }

        for(int i =0;i <zeroes; i++){
            nums[i] = 0;
        }
        for(int i = zeroes; i< zeroes+ ones; i++){
            nums[i] = 1;
        }

        for(int i= zeroes+ ones; i<nums.size(); i++){
            nums[i] = 2;
        }
    }
};