class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
      int n = board.size();
      vector<int> flatBoard;
      for (int i = 0; i < n; i++) {
        if (i % 2 != 0) {
          reverse(board[n - i - 1].begin(), board[n - i - 1].end());
        }
        for (int j = 0; j < board[n - i - 1].size(); j++) {
          flatBoard.push_back(board[n - i - 1][j]);
        }
      }
      int ans = 0;
      queue<int> q;
      unordered_set<int> seen;
      
      q.push(0);
      seen.insert(0);
      while (!q.empty()) {
        for (int i = q.size(); i > 0; i--) {
          int cur = q.front();
          q.pop();
          if (cur == n * n - 1) {
            return ans;
          }
          for (int j = cur + 1; j < min(cur + 7, n * n); j++) {
            int temp = j;
            if (flatBoard[j] != -1) {
              temp = flatBoard[j] - 1;
            }
            if (seen.find(temp) == seen.end()) {
              seen.insert(temp);
              q.push(temp);
            }
          }
        }
        ans++;
      }
      return -1;
    }
};
