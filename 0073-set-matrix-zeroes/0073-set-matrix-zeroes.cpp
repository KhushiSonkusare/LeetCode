class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        set<int> iidx;
        set<int> jidx;

        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[0].size(); j++){
                if(matrix[i][j] == 0){
                    iidx.insert(i);
                    jidx.insert(j);
                }
            }
        }

        for(auto i : iidx){
            for(int k = 0; k < matrix[0].size(); k++){
                matrix[i][k] = 0;
            }
        }

        for(auto j : jidx){
            for(int k = 0; k < matrix.size(); k++){
                matrix[k][j] = 0;
            }
        }
    }
};
