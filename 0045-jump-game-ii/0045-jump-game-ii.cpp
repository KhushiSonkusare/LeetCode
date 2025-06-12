class Solution {
public:
    int jump(vector<int>& nums) {
        int maxi = 0, jumps = 0, curr = 0;
        for(int i = 0; i< nums.size()-1; i++){
            maxi = max(maxi, i+ nums[i]);
            if(curr == i){ jumps++;
            curr = maxi;}

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