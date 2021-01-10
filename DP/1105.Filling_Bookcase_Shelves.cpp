class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelf_width) {
      int n = books.size();
      books.insert(books.begin(), {0, 0});
      vector<int>dp(n + 1, INT_MAX);
      dp[0] = 0;
      
      for (int i = 1; i < n + 1; i++) {
        int curHeight = INT_MIN, curWidth = 0;
        for (int j = i; j >= 1; j--) {
          curHeight = max(curHeight, books[j][1]);
          curWidth += books[j][0];
          if (curWidth > shelf_width) 
            break;
          dp[i] = min(dp[i], dp[j-1] + curHeight);
        }
      }
      return dp[n];
    }
};
