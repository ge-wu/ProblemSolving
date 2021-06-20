class Solution {
public:
    int m, n;
    int countSubIslands(vector<vector<int>>& A, vector<vector<int>>& B) {
        m = A.size();
        n = A[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (!A[i][j]) {
                    dfs(B, i, j);
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (B[i][j]) {
                    dfs(B, i, j);
                    ++ans;
                }
            }
        }
        return ans;
    }
    void dfs(vector<vector<int>> &grid, int i, int j) {
        if (i < 0 || i >= m || j < 0 || j >= n || !grid[i][j]) {
            return;
        }
        grid[i][j] = 0;
        dfs(grid, i + 1, j);
        dfs(grid, i - 1, j);
        dfs(grid, i, j + 1);
        dfs(grid, i, j - 1);
    }
};
