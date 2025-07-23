class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int rows = mat.size(), cols = mat[0].size();
        queue<pair<int,int>> q;
        vector<vector<int>> dist(rows, vector<int>(cols, INT_MAX));
   
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if(mat[i][j] == 0) {
                    dist[i][j] = 0;  
                    q.push({i, j});
                }
            }
        }
        

        vector<pair<int,int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};
        
    
        while(!q.empty()) {
            auto [r, c] = q.front();
            q.pop();
            
            for(auto [dr, dc] : dirs) {
                int nr = r + dr, nc = c + dc;
                
                if(nr >= 0 && nr < rows && nc >= 0 && nc < cols &&
                   dist[nr][nc] > dist[r][c] + 1) {
                    
                    dist[nr][nc] = dist[r][c] + 1;
                    q.push({nr, nc});
                }
            }
        }
        
        return dist;
    }
};
