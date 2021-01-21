class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        if (n == 1) return triangle[0][0];
        
        vector<vector<int>> dp(n);
        dp[0] = triangle[0];
        
        for (int i = 1; i < n; i++) {
            dp[i] = vector<int>(triangle[i].size(), 0);
            for (int j = 0; j < triangle[i].size(); j++) {
                dp[i][j] = triangle[i][j];
                if (!j)
                    dp[i][j] += dp[i - 1][0];
                else if (j == triangle[i].size() - 1) 
                    dp[i][j] += dp[i - 1][j - 1];
                else 
                    dp[i][j] += min(dp[i - 1][j - 1], dp[i - 1][j]);
            }
        }
        return *min_element(dp[n - 1].begin(), dp[n - 1].end());
    }
};
