class Solution {
public:
    void dfs(vector<vector<int>>& grid, int row, int col, vector<vector<int>>& vis) {
        int n = grid.size();
        int m = grid[0].size();
        if (row < 0 || col < 0 || row >= n || col >= m || grid[row][col] == 0 || vis[row][col])
            return;

        vis[row][col] = 1;

        dfs(grid, row + 1, col, vis);
        dfs(grid, row - 1, col, vis);
        dfs(grid, row, col + 1, vis);
        dfs(grid, row, col - 1, vis);
    }

    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));

        for(int j = 0; j < m; j++) {
            if(grid[0][j] == 1 && !vis[0][j])
                dfs(grid, 0, j, vis);
            if(grid[n - 1][j] == 1 && !vis[n - 1][j])
                dfs(grid, n - 1, j, vis);
        }

        for(int i = 0; i < n; i++) {
            if(grid[i][0] == 1 && !vis[i][0])
                dfs(grid, i, 0, vis);
            if(grid[i][m - 1] == 1 && !vis[i][m - 1])
                dfs(grid, i, m - 1, vis);
        }

        int cnt = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1 && !vis[i][j])
                    cnt++;
            }
        }

        return cnt;
    }
};
