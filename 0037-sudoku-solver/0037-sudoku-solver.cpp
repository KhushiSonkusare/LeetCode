class Solution {
public:
    bool check(vector<vector<char>>& board, char digit, int row, int col) {
        for (int i = 0; i < 9; i++) {
            if (board[i][col] == digit) return false;   // check column
            if (board[row][i] == digit) return false;   // check row
            if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == digit) 
                return false;                          // check 3x3 box
        }
        return true;
    }

    bool helper(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    for (int d = 1; d <= 9; d++) {
                        char digit = d + '0';
                        if (check(board, digit, i, j)) {
                            board[i][j] = digit;
                            if (helper(board)) return true; // solved
                            board[i][j] = '.';              // backtrack
                        }
                    }
                    return false; // no valid digit → dead end
                }
            }
        }
        return true; // board filled successfully
    }

    void solveSudoku(vector<vector<char>>& board) {
        helper(board);
    }
};
