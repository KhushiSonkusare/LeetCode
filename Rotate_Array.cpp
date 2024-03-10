class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        for(int i = 0; i<k; i++){
            long long temp = nums[nums.size()-1];
            for(int j = nums.size()-1; j>0; j--){
                nums[j] = nums[j-1];
            }
            nums[0] = temp;
        }
    }
};