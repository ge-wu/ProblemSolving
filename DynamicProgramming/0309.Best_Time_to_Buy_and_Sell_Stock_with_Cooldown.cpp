class Solution {
public:
    int maxProfit(vector<int>& p) {
      int n = p.size();
      int hold = INT_MIN, sold = 0, cooled = 0;
      for (int i = 0; i < n; i++) {
        int h = hold, s = sold, c = cooled;
        hold = max(h, c - p[i]);
        sold = h + p[i];
        cooled = max(c, s);
      }
      return max(sold, cooled);
    }
};
