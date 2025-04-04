#include <vector>
#include <set>
#include <algorithm> // For sort

using std::vector;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::set<vector<int>> uniqueTriplets; 
        
    
        std::sort(nums.begin(), nums.end());
        
        for (int i = 0; i < nums.size(); ++i) {
       
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            
            for (int j = i + 1; j < nums.size(); ++j) {
         
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;
                
                for (int k = j + 1; k < nums.size(); ++k) {
                
                    if (k > j + 1 && nums[k] == nums[k - 1]) continue;
                    
                    if (nums[i] + nums[j] + nums[k] == 0) {
                        uniqueTriplets.insert({nums[i], nums[j], nums[k]});
                    }
                }
            }
        }
       
        vector<vector<int>> result(uniqueTriplets.begin(), uniqueTriplets.end());
        return result;
    }
};
