class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size(), m = obstacleGrid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (obstacleGrid[i][j] != 1) {
                    if (i + j == 0) {
                        dp[i][j] = 1;
                    } else {
                        int left = j - 1 < 0 ? 0 : dp[i][j - 1];
                        int up = i - 1 < 0 ? 0 : dp[i - 1][j];
                        dp[i][j] = left + up;
                    }
                }
            }
        }
        return dp[n - 1][m - 1];
    }
};
