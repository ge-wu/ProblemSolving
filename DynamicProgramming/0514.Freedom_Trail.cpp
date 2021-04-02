class Solution {
public:
    int findRotateSteps(string ring, string key) {
        int m = ring.size();
        int n = key.size();
        vector<vector<int>> dp(n, vector<int>(m, INT_MAX));
        unordered_map<char, vector<int>> idxes;
        
        for (int i = 0; i < m; i++) {
            idxes[ring[i]].push_back(i);
        }
        
        for (int i: idxes[key[0]]) {
            dp[0][i] = min(dp[0][i], min(i, m - i));
        }
        
        for (int i = 1; i < n; i++) {
            for (int curIdx: idxes[key[i]]) {
                for (int preIdx: idxes[key[i - 1]]) {
                    int curMinDist = min(abs(curIdx - preIdx), 
                        m - abs(curIdx - preIdx));
                    dp[i][curIdx] = min(dp[i][curIdx], 
                        dp[i - 1][preIdx] + curMinDist);
                }
            }
        }
        
        int ans = INT_MAX;
        for (int idx: idxes[key[n - 1]]) {
            ans = min(ans, dp[n - 1][idx]);
        }
        return ans + n;
    }
};
