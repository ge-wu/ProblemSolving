class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        vector<int> dp(3, 0);
        dp[1] = dp[2] = INT_MIN;
        
        for (int i = 0; i < nums.size(); i++) {
            vector<int> dp_copy = dp;
            int k = nums[i] % 3;
            for (int j = 0; j < 3; j++) {
                dp[j] = max(dp_copy[j], dp_copy[(j - k + 3) % 3] + nums[i]);
            }
        }
        return dp[0];
    }
};
