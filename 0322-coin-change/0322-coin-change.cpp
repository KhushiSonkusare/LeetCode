class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size(), vector<int> (amount + 1, 0));

        for (int i = 0; i <= amount; i++) {
            if (i % coins[0] == 0) {
                dp[0][i] = i / coins[0];
            } else {
                dp[0][i] = 1e9;
            }
        }

        for (int ind = 1; ind < coins.size(); ind++) {
            for (int tar = 0; tar <= amount; tar++) {
                int nottaken = dp[ind - 1][tar];
                int taken = 1e9;
                if (coins[ind] <= tar) {
                    taken = 1 + dp[ind][tar - coins[ind]];
                }
                dp[ind][tar] = min(nottaken, taken);
            }
        }

        int ans = dp[coins.size() - 1][amount];
        return (ans == 1e9) ? -1 : ans;
    }
};
