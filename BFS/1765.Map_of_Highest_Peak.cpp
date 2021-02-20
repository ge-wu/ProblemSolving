class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        queue<pair<int, int>> q;        
        vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        int m = isWater.size(), n = isWater[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (isWater[i][j]) {
                    isWater[i][j] = 0;
                    q.push({i, j});
                } else {
                    isWater[i][j] = INT_MAX;
                }
            }
        }
        int curHeight = 1;
        while (!q.empty()) {
            int a = q.size();
            for (int k = 0; k < a; k++) {
                pair<int, int> cur = q.front();
                q.pop();
                int i = cur.first, j = cur.second;
                for (auto & dir: dirs) {
                    int x = i + dir.first, y = j + dir.second;
                    if (x < 0 || y < 0 || x >= m || y >= n)
                        continue; 
                    if (curHeight < isWater[x][y]) {
                        isWater[x][y] = curHeight;
                        q.push({x, y});
                    }
                }
            }
            curHeight++;
        }
        return isWater;
    }
};
