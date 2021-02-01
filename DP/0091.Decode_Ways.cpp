class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        s = "#" + s;
        
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        dp[1] = (s[1] != '0') ? 1 : 0;
        for (int i = 2; i <= n; i++) {
            if (s[i] != '0') {
                dp[i] += dp[i - 1];
            }
            if (s[i] >= '0' && s[i] <= '6' && (s[i - 1] == '1' || s[i - 1] == '2')) {
                dp[i] += dp[i - 2];
            } else if (s[i] >= '7' && s[i] <= '9' && s[i - 1] == '1') {
                dp[i] += dp[i - 2];
            }
        }
        return dp[n];
    }
};
