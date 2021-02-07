class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
      int n = grid.size();
      queue<pair<int, int>> q;
      vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
      
      for (int i = 0; i < n; i++) 
        for (int j = 0; j < n; j++)
          if (grid[i][j]) 
            q.push({i, j});

      int ans = 0;
      while (!q.empty()) {
        ans++;
        for (int k = q.size(); k > 0; --k) {
          int i = q.front().first, j = q.front().second;
          q.pop();
          for (auto & dir: dirs) {
            int x = dir.first + i, y = dir.second + j;
            if (x >= 0 && x < n && y >= 0 && y < n && grid[x][y] == 0) {
              grid[x][y] = 1;
              q.push({x, y});
            }
          }
        }
      }
      return ans == 1 ? -1 : ans - 1;
    }
};
