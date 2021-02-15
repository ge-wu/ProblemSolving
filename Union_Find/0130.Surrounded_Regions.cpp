class Solution {
public:
  unordered_map<int, int> parents;
  void solve(vector<vector<char>>& board) {
    int n = board.size();
    if (!n) 
      return;
    int m = board[0].size();
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (board[i][j] == 'O') {
          if (i == 0 || j == 0 || i == n - 1 || j == m - 1) 
            parents[i * n + j] = -1;
          else 
            parents[i * n + j] = i * n + j;
        }
      }
    }
    
    vector<pair<int, int>> dirs = {{0, 1}, {-1, 0}, {1, 0}, {0, -1}};
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (board[i][j] == 'X') 
          continue;
        for (auto & dir: dirs) {
          int x = i + dir.first, y = j + dir.second;
          if (x < 0 || x >= n || y < 0 || y >= m || board[x][y] == 'X')
            continue;
          Union(x * n + y, i * n + j);
        }
      }
    }
    
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (board[i][j] == 'O')
          if (Find(i * n + j) != -1) 
            board[i][j] = 'X';
      }
    }
  }
  
  int Find(int x) {
    if (parents[x] == -1) 
      return -1;
    if (parents[x] != x)
      parents[x] = Find(parents[x]);
    return parents[x];
  }
  
  void Union(int x, int y) {
    x = Find(x);
    y = Find(y);
    if (x != y) 
      parents[x] = y;
  }
};
