class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
      vector<int>year(366, 0);
      vector<int>dp(366, INT_MAX);
      int lastDay = days[days.size() - 1];
      
      for (int day: days) year[day] = 1;
      
      dp[0] = 0;
      for (int i = 1; i <= lastDay; i++) {
        if (year[i]) {
          int one = dp[max(0, i - 1)] + costs[0];
          int seven = dp[max(0, i - 7)] + costs[1];
          int thirty = dp[max(0, i - 30)] + costs[2];
          dp[i] = min(one, min(seven, thirty));
        } else {
          dp[i] = dp[i-1];
        }
      }
      return dp[lastDay];
    }
};
