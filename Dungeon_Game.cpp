#include <vector>
#include <algorithm> // for max and min functions

using namespace std;

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size();
        int n = dungeon[0].size();

        // Create a 2D vector to store the minimum health required
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, INT_MAX));

        // Set the health required to reach the bottom-right cell
        dp[m][n - 1] = dp[m - 1][n] = 1;

        // Iterate through the dungeon starting from the bottom-right corner
        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                // Calculate the minimum health required to reach the current cell
                int min_health = min(dp[i + 1][j], dp[i][j + 1]) - dungeon[i][j];
                dp[i][j] = max(1, min_health); // Ensure health doesn't drop below 1
            }
        }

        return dp[0][0];
    }
};

