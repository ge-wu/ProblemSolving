class Solution {
public:
    void solve(vector<vector<char>>& board) {
      queue<pair<int, int>> q;
      vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
      int n = board.size();
      if (!n) 
        return;
      int m = board[0].size();
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
          if (i == 0 || j == 0 || i == n - 1 || j == m - 1) 
            if (board[i][j] == 'O') {
              q.push({i, j});
              board[i][j] = '-';
            }
        }
      }
      
      while (!q.empty()) {
        for (int i = q.size(); i > 0; i--) {
          auto cur = q.front();
          q.pop();
          for (auto & dir: dirs) {
            int x = cur.first + dir.first;
            int y = cur.second + dir.second;
            if (x < 0 || x >= n || y < 0 || y >= m) 
              continue;
            if (board[x][y] == '-' || board[x][y] == 'X') 
              continue;
            board[x][y] = '-';
            q.push({x, y});
          }
        }
      }
      
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
          if (board[i][j] == '-') 
            board[i][j] = 'O';
          else if (board[i][j] == 'O') 
            board[i][j] = 'X';
        }
      }
    }
};
