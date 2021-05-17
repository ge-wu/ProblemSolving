class Solution {
public:
    vector<vector<int>> w;
    int m, n;

    int numEnclaves(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        w = grid;
        for (int i = 0; i < m; i++) {
            dfs(i, 0);
            dfs(i, n - 1);
        }
        for (int i = 0; i < n; i++) {
            dfs(0, i);
            dfs(m - 1, i);
        }

        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                ans += w[i][j];
            }
        }
        return ans;
    }

    void dfs(int i, int j) {
        if (i < 0 || j < 0 || i >= m || j >= n || !w[i][j])
            return;
        w[i][j] = 0;
        dfs(i + 1, j);
        dfs(i - 1, j);
        dfs(i, j + 1);
        dfs(i, j - 1);
    }
};
