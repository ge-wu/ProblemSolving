class Solution {
public:
  int numIslands(vector<vector<char>>& g) {

    if (g.size() == 0)
      return 0;

    int n = g.size(), m = g[0].size();
    vector<int> parents(n * m + 1, 0);
    vector<vector<int>> grid(n, vector<int>(m, 0));

    for (int i = 0; i <= n * m; i++) {
      parents[i] = i;
    }
    
    int M = 0, label = 1;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        grid[i][j] = g[i][j] - '0';
      }
    }
    
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (grid[i][j] != 1)
          continue;
        vector<int> pn = getPriorNeighbors(i, j, n, m, grid);
        if (pn.empty()) {
          M = label;
          label++;
        } else {
          M = *min_element(pn.begin(), pn.end());
        }
        grid[i][j] = M;
        for (int x: pn)
          if (x != M) 
            Union(x, M, parents);
      }
    }
    unordered_set<int> set;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (grid[i][j]) {
          grid[i][j] = Find(grid[i][j], parents);
          set.insert(grid[i][j]);
        }
      }
    }    
    return set.size();
  }
  
  vector<int> getPriorNeighbors(
    int i, int j, int n, int m, vector<vector<int>>& grid) {
    vector<pair<int, int>> dirs = {{0, -1}, {-1, 0}};
    vector<int> ans;
    for (auto &dir: dirs) {
      int x = dir.first + i, y = dir.second + j;
      if (x < 0 || y < 0 ||x >= n || y >= m) 
        continue;
      if (grid[x][y] != 0)
        ans.push_back(grid[x][y]);
    }
    return ans;
  }
  
  void Union(int x, int y, vector<int>& parents) {
    int xp = Find(x, parents);
    int yp = Find(y, parents);
    if (xp != yp) 
      parents[xp] = yp;
  }
  
  int Find(int x, vector<int>& parents) {
    if (parents[x] == x) 
      return x;
    else
      return parents[x] = Find(parents[x], parents);
  }
};
