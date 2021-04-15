class Solution {
public:
    vector<vector<string>> ans;
    vector<string> grid;
    int n;

    vector<vector<string>> solveNQueens(int n_) {
        n = n_;
        string temp = "";
        for (int i = 0; i < n; i++) temp.push_back('.');
        for (int i = 0; i < n; i++) grid.push_back(temp);
        
        dfs(grid);
        
        return ans;
    }
    
    void dfs(vector<string> &grid, int idx=0) {
        if (idx == n) {
            ans.push_back(grid);
            return;
        }
        for (int i = 0; i < n; i++) {
            grid[idx][i] = 'Q';
            if (isValid(idx, i)) {
                dfs(grid, idx + 1);
            }
            grid[idx][i] = '.';
        }
    }
    
    bool isValid(int x, int y) {
        for (int i = x - 1; i >= 0; i--) {
            if (grid[i][y] == 'Q') 
                return false;
        }
        for (int i = x - 1, j = y - 1; i >= 0 && j >= 0; i--, j--) {
            if (grid[i][j] == 'Q') 
                return false;
        }
        for (int i = x - 1, j = y + 1; i >= 0 && j < n; i--, j++) {
            if (grid[i][j] == 'Q') 
                return false;
        }
        return true;
    }
};
