class Solution {
public:
    int search(vector<int>& nums, int target) {
        auto it = std::find(nums.begin(), nums.end(), target);
        if(it!=nums.end()){
            int index = std::distance(nums.begin(), it);
            return index;
        }
        return -1;
    }
};