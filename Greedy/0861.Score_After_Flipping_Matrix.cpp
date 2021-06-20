/* It is obvious that 1000 > 0111. So we want every entry of 
column 0 to have 1 by flip is row. Next, we only filp the 
column with more 0 than 1, otherwise, it will make the result
lesser. Finally, add up each row */
class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; ++i) {
            if (!grid[i][0]) {
                for (int j = 0; j < n; ++j) {
                    grid[i][j] = 1 - grid[i][j];
                }
            }

        }
        for (int i = 0; i < n; ++i) {
            int cnt = 0;
            for (int j = 0; j < m; ++j) {
                cnt += grid[j][i];
            }
            if (cnt < m - cnt) {
                for (int j = 0; j < m; ++j) {
                    grid[j][i] = 1 - grid[j][i];
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            int cur = 0;
            for (int j = 0; j < n; ++j) {
                cur = cur * 2 + grid[i][j];
            }
            ans += cur;
        }
        return ans;
    }
};
