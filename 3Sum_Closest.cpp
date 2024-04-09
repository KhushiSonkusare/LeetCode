#include <vector>
#include <algorithm> // For sort
#include <cmath>     // For abs

using std::vector;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        std::sort(nums.begin(), nums.end());
        int n = nums.size();
        int closestSum = nums[0] + nums[1] + nums[2]; 
        int minDiff = std::abs(target - closestSum); 

        for (int i = 0; i < n - 2; ++i) {
            int left = i + 1;
            int right = n - 1;
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                int currentDiff = std::abs(target - sum); 
                if (currentDiff < minDiff) {
                    minDiff = currentDiff;
                    closestSum = sum;
                }
                if (sum < target) {
                    ++left;
                } else {
                    --right;
                }
            }
        }
        
        return closestSum;
    }
};
