class Solution {
public:
    bool checkXMatrix(vector<vector<int>>& grid) {
        bool flag = true;
        for(int i = 0; i<grid.size(); i++){
            for(int j = 0; j<grid[i].size(); j++){
                if(i == j){
                    if(grid[i][j] == 0){
                        flag = false;
                        break;
                    }
                }
            }
        }

        return flag;
    }
};