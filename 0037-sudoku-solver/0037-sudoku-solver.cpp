class Solution {
public:
    bool safe(char digit, int i, int j, vector<vector<char>>& board) {
        for (int k = 0; k < 9; k++) {
            if (board[k][j] == digit) return false; // check column
            if (board[i][k] == digit) return false; // check row
        }

        int rowStart = 3 * (i / 3);
        int colStart = 3 * (j / 3);
        for (int a = rowStart; a < rowStart + 3; a++) {
            for (int b = colStart; b < colStart + 3; b++) {
                if (board[a][b] == digit) return false;
            }
        }

        return true;
    }

    bool helper(vector<vector<char>>& board) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (board[i][j] == '.') {
                    for (char digit = '1'; digit <= '9'; digit++) {
                        if (safe(digit, i, j, board)) {
                            board[i][j] = digit;
                            if (helper(board)) return true;
                            board[i][j] = '.'; // backtrack
                        }
                    }
                    return false; // no valid digit
                }
            }
        }
        return true; // all cells filled
    }

    void solveSudoku(vector<vector<char>>& board) {
        helper(board);
    }
};
