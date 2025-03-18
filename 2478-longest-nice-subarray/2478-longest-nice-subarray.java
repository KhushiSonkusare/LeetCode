class Solution {
    public int longestNiceSubarray(int[] nums) {
        if (nums.length == 1) return 1;

        int max = 1;
        int l = 0;
        int r = 0;
        int len = 1;

        int n = nums.length;

        // Use a while loop to move r until the end of the array
        while (r < n - 1) {
            boolean isNice = true;

            // Check if nums[r+1] conflicts with the window from l to r
            for (int i = l; i <= r; i++) {
                if ((nums[i] & nums[r + 1]) != 0) {
                    isNice = false;
                    break;
                }
            }

            if (isNice) {
                r++;
                len = r - l + 1; // update the length of the current window
                max = Math.max(max, len); // update max if necessary
            } else {
                l++; // move left pointer to exclude conflicting elements
                if (l > r) {
                    r = l; // reset r if it falls behind l
                }
            }
        }

        return max;
    }
}
