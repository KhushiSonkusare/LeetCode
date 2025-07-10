class Solution {
public:
    vector<vector<int>> grid;
    int m, n;
    int ans = 0;

    void helper(int i, int j) {
        if (i < 0 || j < 0 || i >= m || j >= n) return;
        if (grid[i][j] == -1 || grid[i][j] == 3) return;

        if (grid[i][j] == 2) {
            for (int x = 0; x < m; x++) {
                for (int y = 0; y < n; y++) {
                    if (grid[x][y] == 0) return;
                }
            }
            ans++;
            return;
        }
        int temp = grid[i][j];
        grid[i][j] = 3;

        helper(i + 1, j);
        helper(i - 1, j);
        helper(i, j + 1);
        helper(i, j - 1);

        grid[i][j] = temp;
    }

    int uniquePathsIII(vector<vector<int>>& g) {
        grid = g;
        m = grid.size();
        n = grid[0].size();

        int startX = 0, startY = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    startX = i;
                    startY = j;
                    break;
                }
            }
        }

        helper(startX, startY);
        return ans;
    }
};
