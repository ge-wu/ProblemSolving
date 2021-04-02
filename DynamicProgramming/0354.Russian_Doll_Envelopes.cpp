class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& env) {
        int n = env.size();
        sort(env.begin(), env.end());
        vector<int> dp(n, 1);

        // Longest increasing subsequence
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (env[j][1] < env[i][1] && env[j][0] < env[i][0]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};
