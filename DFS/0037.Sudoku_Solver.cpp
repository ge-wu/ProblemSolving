class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        dfs(board);
    }
    
    bool dfs(vector<vector<char>> &board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') continue;
                for (char c = '1'; c <= '9'; c++) {
                    if (checkValid(board, i, j, c)) {
                        board[i][j] = c;
                        if (dfs(board)) return true;
                        else board[i][j] = '.';
                    }
                }
                return false;
            }
        }
        return true;
    }
    
    bool checkValid(vector<vector<char>> &board, int row, int col, char c) {
        for (int i = 0; i < 9; i++) {
            if (board[i][col] == c || board[row][i] == c) return false; 
            if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c) return false;
        }
        return true;
    }
};
