class Solution {
public:
    int minSteps(int n) {
        vector<int>dp(n + 1, INT_MAX);
        dp[1] = 0;
        for (int i = 2; i <= n; i++) {
            for (int j = 2; j <= i; j++) {
                if (!(i % j)) {
                    dp[i] = min(dp[i], dp[i / j] + j);
                    // Greedy. Since paste most number of "A" is 
                    // most efficient. No need check other factors. 
                    break;
                }
            }
        }
        return dp[n];
    }
};
