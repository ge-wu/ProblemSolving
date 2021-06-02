class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size(), ans = 0;
        if (grid[0][0] || grid[n-1][n-1])
            return -1;
        if (n == 1) 
            return 1;
        vector<pair<int, int>> dirs = {
            {0, 1}, {0, -1}, {1, 0}, {-1, 0},
            {1, -1}, {-1, 1}, {1, 1}, {-1, -1}
        };
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        queue<pair<int, int>> q;
        q.push({0, 0});
        while (!q.empty()) {
            int k = q.size();
            while (k--) {
                int x = q.front().first, y = q.front().second;
                if (x == n - 1 && y == n - 1)
                    return ans + 1;
                q.pop();
                for (auto &d: dirs) {
                    int i = x + d.first, j = y + d.second;
                    if (i < 0 || j < 0 || i >= n || j >= n || visited[i][j] || grid[i][j])
                        continue;
                    q.push({i, j});
                    visited[i][j] = true;
                }
            }
            ans++;
        }
        return -1;
    }
};
