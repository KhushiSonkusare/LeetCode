class Solution {
public:
    bool helper(vector<vector<char>>& board, string &word, int ind, int i, int j, int rows, int cols) {
        if (ind == word.size()) {
            return true; 
        }

        if (i < 0 || j < 0 || i >= rows || j >= cols || word[ind] != board[i][j] || board[i][j] == '!') {
            return false;
        }

        char c = board[i][j];
        board[i][j] = '!'; 
        bool found = helper(board, word, ind + 1, i - 1, j, rows, cols) ||  // up
                     helper(board, word, ind + 1, i + 1, j, rows, cols) ||  // down
                     helper(board, word, ind + 1, i, j - 1, rows, cols) ||  // left
                     helper(board, word, ind + 1, i, j + 1, rows, cols);    // right

        board[i][j] = c; 
        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        int cols = board[0].size();

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (board[i][j] == word[0]) {
                    if (helper(board, word, 0, i, j, rows, cols)) {
                        return true;
                    }
                }
            }
        }

        return false;
    }
};
