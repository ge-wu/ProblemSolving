class Solution {
public:
    int countVowelPermutation(int n) {
        vector<vector<int>> ref = {{1}, {0, 2}, {0, 1, 3, 4}, {2, 4}, {0}};
        vector<vector<int>> dp(n + 1, vector<int>(5, 0));
        dp[1] = {1, 1, 1, 1, 1};
        for (int i = 2; i <= n; ++i) {
            for (int j = 0; j < 5; ++j) {
                for (int k: ref[j]) {
                    dp[i][j] = (dp[i][j] + dp[i - 1][k]) % 1000000007;
                }
            }
        }
        int ans = 0;
        for (int i: dp[n]) {
            ans = (ans + i) % 1000000007;
        }
        return ans;
    }
};
