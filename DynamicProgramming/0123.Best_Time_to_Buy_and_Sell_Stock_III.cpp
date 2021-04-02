class Solution {
public:
    int maxProfit(vector<int>& p) {
      int hold1 = INT_MIN, sold1 = 0;
      int hold2 = INT_MIN, sold2 = 0;
      
      for (int i = 0; i < p.size(); i++) {
        int h1 = hold1, s1 = sold1;
        int h2 = hold2, s2 = sold2;
        hold1 = max(h1, -p[i]);
        sold1 = max(h1 + p[i], s1);
        hold2 = max(h2, s1 - p[i]);
        sold2 = max(h2 + p[i], s2);
      }
      return max(sold2, sold1);
    }
};
