class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        queue<pair<int, int>> q;
        unordered_set<string> seen;
        int n = matrix.size(), m = matrix[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == 0) {
                    q.push({i, j});
                    seen.insert(to_string(i) + ":" + to_string(j));
                }
            }
        }
        int step = 1;
        while (!q.empty()) {
            for (int i = q.size(); i > 0; i--) {
                int a = q.front().first, b = q.front().second;
                q.pop();
                for (auto &dir: dirs) {
                    int x = dir.first + a, y = dir.second + b;
                    if (x < 0 || x >= n || y < 0 || y >= m) 
                        continue;
                    string encoded = to_string(x) + ":" + to_string(y);
                    if (seen.find(encoded) != seen.end()) 
                        continue;
                    seen.insert(encoded);
                    if (matrix[x][y] == 1) {
                        matrix[x][y] = step;
                    }
                    q.push({x, y});
                }
            }
            step++;
        }
        return matrix;
    }
};
