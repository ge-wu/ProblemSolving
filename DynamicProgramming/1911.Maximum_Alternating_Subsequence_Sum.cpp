class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        long long dp[2] = {};
        for (int i = 0; i < n; ++i) {
            long long temp[2] = {};
            temp[0] = max(dp[1] + nums[i], dp[0]);
            temp[1] = max(dp[0] - nums[i], dp[1]);
            swap(dp, temp);
        }
        return max(dp[0], dp[1]);
    }
};
