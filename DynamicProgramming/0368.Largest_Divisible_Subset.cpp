class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
      int n = nums.size();
      if (!n) 
        return {};
      
      vector<int>dp(n, 1);
      vector<int>prev(n, -1);
      sort(nums.begin(), nums.end());
      
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
          if (nums[i] % nums[j] == 0) {
            dp[i] = max(dp[i], dp[j] + 1);
            if (dp[i] == dp[j] + 1) 
              prev[i] = j;
          }
        }
      }
      int maxLen = *max_element(dp.begin(), dp.end());
      auto it = find(dp.begin(), dp.end(), maxLen);
      int idx = it - dp.begin();

      vector<int>ans;
      while (idx != -1) {
        ans.push_back(nums[idx]);
        idx = prev[idx];
      }
      return ans;
    }
};
