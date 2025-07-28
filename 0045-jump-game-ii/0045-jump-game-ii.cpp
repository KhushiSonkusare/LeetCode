class Solution {
public:
    int jump(vector<int>& nums) {
        int maxi = 0, jump = 0, curr = 0;

        for(int i = 0; i<nums.size() -1; i++){
            maxi = max(maxi,i + nums[i]);
            if(curr == i){
                curr = maxi;
                jump++;
            }
        }

        return jump;
    }
};