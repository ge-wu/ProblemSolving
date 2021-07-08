class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int m = A.size(), n = B.size(), ans = INT_MIN, dp[1001][1001];
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (A[i - 1] == B[j - 1]) {
                    dp[i][j] += dp[i - 1][j - 1] + 1;
                } 
                ans = max(ans, dp[i][j]);
            }
        }
        return ans;
    }
};
