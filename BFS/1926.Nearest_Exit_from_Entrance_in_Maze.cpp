class Solution {
public:
    int nearestExit(vector<vector<char>>& A, vector<int>& ent) {
        int ans = 0, m = A.size(), n = A[0].size();
        vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        queue<pair<int, int>> q;
        q.push({ent[0], ent[1]});
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        visited[ent[0]][ent[1]] = true;
        
        while (!q.empty()) {
            ans++;
            for (int i = q.size(); i > 0; --i) {
                int a = q.front().first, b = q.front().second;
                q.pop();
                for (auto dir: dirs) {
                    int x = dir.first + a, y = dir.second + b;
                    if (x < 0 || x >= m || y < 0 || y >= n || visited[x][y] || A[x][y] == '+') {
                        continue;
                    }
                    if (x == 0 || x == m - 1 || y == 0 || y == n - 1) {
                        return ans;
                    }
                    visited[x][y] = true;
                    q.push({x, y});
                }
            }
        }
        return -1;
    }
};
