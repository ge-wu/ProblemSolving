class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
      int n = A.size();
      vector<vector<int>>dp(n, vector<int>(n, 0));
      dp[0] = A[0];
      for (int i = 1; i < n; i++) {
        for (int j = 0; j < n; j++) {
          int curMin = 1000000;
          if (j == 0) {
            curMin = min(dp[i-1][j], dp[i-1][j+1]);
          } else if (j == n - 1) {
            curMin = min(dp[i-1][j], dp[i-1][j-1]);
          } else {
            curMin = min({dp[i-1][j], dp[i-1][j-1], dp[i-1][j+1]});
          }
          dp[i][j] = A[i][j] + curMin;
        }
      }
      return *min_element(dp[n-1].begin(), dp[n-1].end());
    }
};
