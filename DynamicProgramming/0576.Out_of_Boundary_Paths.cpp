class Solution {
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<int>> dp(m, vector<int>(n, 0));
        vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        while (maxMove--) {
            auto copy = dp;
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    int total = 0;
                    for (auto d: dirs) {
                        int x = i + d.first, y = j + d.second;
                        if (x < 0 || y < 0 || x >= m || y >= n) {
                            ++total;
                        } else {
                            total += dp[x][y];
                        }
                        total %= 1000000007;
                    }
                    copy[i][j] = total;
                }
            }
            dp = copy;
        }
        return dp[startRow][startColumn];
    }
};
