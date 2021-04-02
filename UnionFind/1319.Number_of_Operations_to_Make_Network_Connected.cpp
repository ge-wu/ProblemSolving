class Solution {
public:
  unordered_map<int, int> parents;
  int makeConnected(int n, vector<vector<int>>& connections) {
    if (connections.size() < n - 1) 
      return -1;
    
    for (int i = 0; i < n; i++) {
      parents[i] = i;
    }
    
    for (auto & conn: connections) {
      if (Find(conn[0]) != Find(conn[1])) {
        Union(conn[0], conn[1]);
      }
    }
    
    for (int i = 0; i < n; i++) {
      parents[i] = Find(i);
    }
    
    int ans = 0;
    for (int i = 0; i < n; i++) {
      if (parents[i] == i) 
        ans++;
    }
    return ans - 1;
  }
  
  void Union(int x, int y) {
    x = Find(x);
    y = Find(y);
    parents[x] = y;
  }
  
  int Find(int x) {
    if (parents[x] != x) 
      parents[x] = Find(parents[x]);
    return parents[x];
  }
};
