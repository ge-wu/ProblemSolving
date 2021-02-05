class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& b) {
      vector<int> solved = {1, 2, 3, 4, 5, 0};
      vector<vector<int>> dirs = {
        {1, 3}, {0, 2, 4}, {1, 5}, 
        {0, 4}, {1, 3, 5}, {2, 4}
      };
      vector<int> board = {
        b[0][0], b[0][1], b[0][2], 
        b[1][0], b[1][1], b[1][2]
      };
      
      queue<vector<int>> q;
      set<vector<int>> seen;
      seen.insert(board);
      q.push(board);
      
      int ans = 0;
      while (!q.empty()) {
        int k = q.size();
        for (int i = 0; i < k; i++) {
          vector<int> cur = q.front(); q.pop();
          
          if (cur == solved) 
            return ans;
          int zeroIdx = find(cur.begin(), cur.end(), 0) - cur.begin();
          for (int dir: dirs[zeroIdx]) {
            swap(cur[zeroIdx], cur[dir]);
            if (seen.find(cur) == seen.end()) {
              seen.insert(cur);
              q.push(cur);
            }
            swap(cur[zeroIdx], cur[dir]);
          }
          
        }
        ans++;
      }
      return -1;
    }
};
