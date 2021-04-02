class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        
        int n = arr.size(), ans = 0, mod = 1000000007;
        unordered_map<int, long long> dp;
        
        for (int i = 0; i < n; i++) {
            dp[arr[i]] = 1;
            for (int j = 0; j < i; j++) {
                int a = arr[i] % arr[j], b = arr[i] / arr[j];
                if (!a) {
                    dp[arr[i]] = (dp[arr[i]] + dp[arr[j]] * dp[b]) % mod;
                }
            }
            ans = (ans + dp[arr[i]]) % mod;
        }
        return ans;
    }
};
