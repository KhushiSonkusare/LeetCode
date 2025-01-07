class Solution {
public:
    int jump(vector<int>& nums) {
        // 2 pointers, near and far
        int l = 0;
        int r = 0;
        int jumps = 0;
        while(r<nums.size()-1){
            int maxi = INT_MIN;
            for(int i = l; i <= r; i++){
                maxi = max(maxi, nums[i]+i);
            }
            l=r+1;
            r=maxi;
            jumps++;
        }

        return jumps;

        // this is o(n), we need to use greedy to get O(n)
        // int n = nums.size();
        // vector<int> dp(n,INT_MAX);
        // dp[0]=0;
        // int soFar = -1;
        // for (int i = 0; i < n-1; i++){
        //      int jumpSize = min(nums[i],n-i-1);
        //      for(int j = 1; j <= jumpSize; j++){
        //         if (dp[i+j] > dp[i]+1){
        //             dp[i+j] = dp[i]+1;
        //             if (soFar < (i+j)) soFar = i+j;
        //         }
        //     }
        // }
        // return dp[dp.size()-1];
    }
};