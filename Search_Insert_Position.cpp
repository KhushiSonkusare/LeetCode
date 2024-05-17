class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int mid = size(nums)/2;
        int low = 0;
        int high = size(nums) - 1;

        while(low<high){
            if(nums[mid] == target){
                return mid;
            }else{
                if(mid>target){
                    high = mid-1;
                }else{
                    low = mid+1;
                }

                mid = (low+high)/2;
            }
        }

        nums.push_back(target);
        sort(nums.begin(), nums.end());
        auto it = std::find(nums.begin(), nums.end(), target);
        if (it != nums.end()) {
            return std::distance(nums.begin(), it);
        }
        return 0;
    }
};