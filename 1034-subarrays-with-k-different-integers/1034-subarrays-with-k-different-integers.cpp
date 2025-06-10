class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMost(nums, k) - atMost(nums, k - 1);
    }

    int atMost(vector<int> nums, int k) {
        unordered_map<int, int> map;
        int left = 0, res = 0;

        for (int i = 0; i < nums.size(); i++) {
            map[nums[i]]++;
            
            while (map.size() > k) {
                map[nums[left]]--;
                if (map[nums[left]] == 0) {
                    map.erase(nums[left]);
                }
                left++;
            }

            res += i - left + 1;
        }

        return res;
    }
};
