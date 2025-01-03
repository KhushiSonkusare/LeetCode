class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefixSum(n);

        prefixSum[0] = nums[0];
        for (int i = 1; i < n; i++) {
            prefixSum[i] = prefixSum[i - 1] + nums[i];
        }

        int totalSum = prefixSum[n - 1];
        int count = 0;
        for (int i = 0; i < n - 1; i++) {
            int first = prefixSum[i];
            int last = totalSum - first;

            if (first > last) {
                count++;
            }
        }
        return count;
    }
};
