#include <vector>

class Solution {
public:
    bool isValidSudoku(std::vector<std::vector<char>>& board) {
        // Use hash sets to record the seen numbers in rows, columns, and sub-boxes
        std::vector<std::vector<bool>> rows(9, std::vector<bool>(9, false));
        std::vector<std::vector<bool>> cols(9, std::vector<bool>(9, false));
        std::vector<std::vector<bool>> boxes(9, std::vector<bool>(9, false));

        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                char num = board[i][j];
                if (num != '.') {
                    int n = num - '1'; 
                    int boxIndex = (i / 3) * 3 + (j / 3);
                    
                    if (rows[i][n] || cols[j][n] || boxes[boxIndex][n]) {
                        return false;
                    }
                    
                    rows[i][n] = true;
                    cols[j][n] = true;
                    boxes[boxIndex][n] = true;
                }
            }
        }

        return true;
    }
};
