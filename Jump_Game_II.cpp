class Solution {
public:
    int jump(vector<int>& nums) {
        int max = 0;
        int k = nums.size() - 1; 
        int count = 0;
        while (k != 0) {
            for (int i = 0; i < k; i++) {
                if (nums[i] + i >= k) {
                    max = i; 
                    break; 
                }
            }
            count++;
            k = max;
        }
        return count;
    }
};
