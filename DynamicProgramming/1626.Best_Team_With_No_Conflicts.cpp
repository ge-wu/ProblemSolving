class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
      int n = scores.size();
      vector<pair<int, int>> players;
      for (int i = 0; i < n; i++) {
        players.push_back({ages[i], scores[i]});
      }
      sort(players.begin(), players.end());
      
      vector<int>dp(n, 0);
      for (int i = 0; i < n; i++) {
        int a1 = players[i].first, s1 = players[i].second;
        dp[i] = s1;
        for (int j = 0; j < i; j++) {
          int a2 = players[j].first, s2 = players[j].second;
          if (a2 <= a1 && s2 <= s1) {
            dp[i] = max(dp[i], dp[j] + s1);
          }
        }
      }
      return *max_element(dp.begin(), dp.end());
    }
};
