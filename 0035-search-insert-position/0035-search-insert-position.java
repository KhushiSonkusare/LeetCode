class Solution {
    public int searchInsert(int[] nums, int target) {
        int l = 0;
        int r = nums.length - 1;
        int mid = l + (r - l) / 2;
        while (l <= r) {
            mid = l + (r - l) / 2; 
            if (nums[mid] == target) {
                return mid;
            } else if (target < nums[mid]) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        if(nums[mid] < target) return mid + 1;
        else return mid;
    }
}