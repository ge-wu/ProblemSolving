class Solution {
public:
    int m, n;
    vector<vector<int>> w;
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        w = grid;
        
        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                ans = max(ans, dfs(i, j));
            }
        }
        return ans;
    }
    
    int dfs(int i, int j) {
        if (i < 0 || j < 0 || i >= m || j >= n || !w[i][j]) 
            return 0;
        w[i][j] = 0;
        return 1 + dfs(i+1,j) + dfs(i-1,j) + dfs(i,j+1) + dfs(i,j-1);
    }
};
