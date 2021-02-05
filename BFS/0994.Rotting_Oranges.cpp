class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
      int n = grid.size(), m = grid[0].size();
      int orangeCnt = 0, turn = 0;
      vector<vector<int>> adj = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
      
      queue<vector<int>> q;
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
          if (grid[i][j] == 2) {
            q.push({i, j});
          } else if (grid[i][j] == 1) {
            orangeCnt++;
          }
        }
      }
      
      if (!orangeCnt) {
        return 0;
      }
      
      while (!q.empty()) {
        int k = q.size();
        turn++;
        for (int i = 0; i < k; i++) {
          vector<int> cur = q.front();
          q.pop();
          for (auto & a: adj) {
            int x = a[0] + cur[0], y = a[1] + cur[1];
            if (x < 0 || x >= n || y < 0 || y >= m) 
              continue;
            if (grid[x][y] == 1) {
              grid[x][y] = 2;
              q.push({x, y});
              orangeCnt--;
            }
          }
        }
      }
      return orangeCnt == 0 ? turn - 1: -1;
    }
};
