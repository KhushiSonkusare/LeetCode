class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if (n < 0)   
            return -1;
        if (n == 1)
            return nums[0] == target ? 0 : -1;
        int l = 0;
        int r = n;
        while (l < r) {
            int m = (l + r) / 2;
            int v = nums[m];
            if (target == v)
                return m;
            if (v >= nums[l]) {
                if (nums[l] <= target && target <= v)
                    r = m;
                else
                    l = m + 1;
            } else {
                if (v <= target && target <= nums[r - 1])
                    l = m + 1;
                else 
                    r = m;
            }
        }
        return -1;
    }
};