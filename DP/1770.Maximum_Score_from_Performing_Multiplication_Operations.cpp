class Solution {
public:
    int maximumScore(vector<int>& nums, vector<int>& multi) {
        int n = nums.size();
        int m = multi.size();
        nums.insert(nums.begin(), 0);
        vector<vector<int>> dp = vector<vector<int>> (m + 1, vector<int>(m + 1, INT_MIN / 2));
        dp[0][0] = 0;
        
        int ans = INT_MIN / 2;
        for (int len = 1; len <= m; len++) {
            for (int i = 0; i <= len; i++) {
                int j = len - i; 
                if (i >= 1)
                    dp[i][j] = max(dp[i][j], dp[i - 1][j] + nums[i] * multi[i + j - 1]);
                if (j >= 1) 
                    dp[i][j] = max(dp[i][j], dp[i][j - 1] + nums[n - j + 1] * multi[i + j - 1]);
                if (len == m) {
                    ans = max(ans, dp[i][j]);
                }
            }
        }
        return ans;
    }
};
