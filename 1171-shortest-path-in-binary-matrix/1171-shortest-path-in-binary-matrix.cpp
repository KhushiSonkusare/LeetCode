class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] != 0 || grid[n-1][n-1] != 0)
            return -1;

        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        vector<pair<int, int>> directions = {
            {-1,-1}, {-1,0}, {-1,1}, {0,-1}, {0,1}, {1,-1}, {1,0}, {1,1}
        };

        queue<pair<int, pair<int, int>>> q;
        dist[0][0] = 1;
        q.push({1, {0, 0}});

        while (!q.empty()) {
            auto [steps, pos] = q.front();
            q.pop();
            int row = pos.first, col = pos.second;

            if (row == n - 1 && col == n - 1)
                return steps;

            for (auto [dr, dc] : directions) {
                int nr = row + dr;
                int nc = col + dc;

                if (nr >= 0 && nr < n && nc >= 0 && nc < n && grid[nr][nc] == 0 && dist[nr][nc] > steps + 1) {
                    dist[nr][nc] = steps + 1;
                    q.push({steps + 1, {nr, nc}});
                }
            }
        }

        return -1;
    }
};
