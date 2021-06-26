class Solution {
public:
    int minimumTotal(vector<vector<int>>& A) {
        int n = A.size();
        vector<vector<int>> dp(n);
        dp[0] = A[0];
        for (int i = 1; i < n; ++i) {
            dp[i] = vector<int>(A[i].size(), 0);
            for (int j = 0; j < A[i].size(); ++j) {
                dp[i][j] = A[i][j];
                if (j == 0) {
                    dp[i][j] += dp[i - 1][0];
                } else if (j == dp[i].size() - 1) {
                    dp[i][j] += dp[i - 1].back();
                } else {
                    dp[i][j] += min(dp[i - 1][j - 1], dp[i - 1][j]);
                }
            }
        }
        return *min_element(dp.back().begin(), dp.back().end());
    }
};
