class Solution {
public:
    void dfs(vector<vector<int>>& image, int r, int c, int orig, int color) {
        int rows = image.size();
        int cols = image[0].size();
        
        // Boundary + same-color check
        if(r < 0 || r >= rows || c < 0 || c >= cols || image[r][c] != orig)
            return;
        
        image[r][c] = color;
        
        dfs(image, r+1, c, orig, color);
        dfs(image, r-1, c, orig, color);
        dfs(image, r, c+1, orig, color);
        dfs(image, r, c-1, orig, color);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int orig = image[sr][sc];
        if(orig == color) return image;  
        
        dfs(image, sr, sc, orig, color);
        return image;
    }
};
