class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        nums1.insert(nums1.begin(), 0);
        nums2.insert(nums2.begin(), 0);
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, INT_MIN / 2));
        
        int ans = INT_MIN;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                dp[i][j] = nums1[i] * nums2[j];
                dp[i][j] += max(0, dp[i-1][j-1]);
                dp[i][j] = max(dp[i][j], max(dp[i-1][j], dp[i][j-1]));
                ans = max(ans, dp[i][j]);
            }
        }
        return ans;
    }
};
