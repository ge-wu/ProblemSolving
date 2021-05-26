class Solution {
public:
    vector<vector<int>> w;
    int m, n;
    
    int uniquePathsIII(vector<vector<int>>& grid) {
        w = grid;
        int cnt = 2, x = -1, y = -1;
        m = grid.size();
        n = grid[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cnt += (grid[i][j] == 0);
                if (grid[i][j] == 1) {
                    x = i;
                    y = j;
                }
            }
        }
        return dfs(x, y, cnt);
    }
    
    int dfs(int i, int j, int c) {
        if (i < 0 || j < 0 || i >= m || j >= n) 
            return 0;
        if (w[i][j] == 3 || w[i][j] == -1) 
            return 0;
        if (w[i][j] == 2) 
            return c == 1;
        w[i][j] = 3;
        c--;
        int temp = dfs(i+1,j,c) + dfs(i-1,j,c) + dfs(i,j+1,c) + dfs(i,j-1,c);
        c++;
        w[i][j] = 0;
        return temp;
    }
};
