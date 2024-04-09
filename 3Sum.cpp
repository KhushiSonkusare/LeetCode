class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        int i = 0;
        int n = nums.size();
        while(i < n-2) {
            if(nums[i] > 0) { break; }
            int left = i+1;
            int right = n-1;
            int target = -nums[i];
            while(left < right) {
                int sum = nums[left] + nums[right];
                if(sum == target) {
                    result.push_back({nums[i], nums[left], nums[right]});
                    while(left+1 < n && nums[left] == nums[left+1]){ left++; }
                    left++;
                } 
                while(left < right && nums[left] + nums[right] < target) { left++; }
                while(left < right && nums[left] + nums[right] > target) { right--; }
            }
            while(i+1 < n && nums[i] == nums[i+1]) { i++; }
            i++;
        }
        return result;
    }
};