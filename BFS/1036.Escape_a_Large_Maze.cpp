class Solution {
public:
  bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target) {
    if (blocked.size() <= 1) {
      return true;
    } 
    unordered_set<string> blocks;
    
    for (auto &b: blocked) {
      blocks.insert(to_string(b[0]) + ":" + to_string(b[1]));
    }
    
    return bfs(source, target, blocks) && bfs(target, source, blocks);
  }
  
  bool bfs(vector<int>& source, vector<int>& target, unordered_set<string>& blocks) {
    vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0,1}, {0, -1}};
    
    queue<vector<int>> q;
    unordered_set<string> seen;
    
    q.push(source);
    seen.insert(to_string(source[0]) + ":" + to_string(source[1]));
    
    while (!q.empty()) {
      vector<int> cur = q.front();
      q.pop();
      for (auto &d: dirs) {
        int x = d[0] + cur[0], y = d[1] + cur[1];
        if (x < 0 || x >= 1e6 || y < 0 || y >= 1e6)
          continue;
        if (x == target[0] && y == target[1]) 
          return true;
        string temp = to_string(x) + ":" + to_string(y);
        if (blocks.find(temp) != blocks.end() || seen.find(temp) != seen.end()) 
          continue;

        q.push({x, y});
        seen.insert(temp);
      }
      if (seen.size() == 20000) 
        return true;
    }
    return false;
  }
};
