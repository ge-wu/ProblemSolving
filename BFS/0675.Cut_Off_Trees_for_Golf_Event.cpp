class Solution {
public:
    vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    vector<vector<int>> F;
    int m, n;

    int cutOffTree(vector<vector<int>>& forest) {
        F = forest;
        m = F.size();
        n = F[0].size();
        
        vector<vector<int>> trees;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (F[i][j] > 1)
                    trees.push_back({F[i][j], i, j});
            }
        }
        sort(trees.begin(), trees.end());
        int ans = 0, x = 0, y = 0;
        for (auto &tree: trees) {
            int temp = findShortestPath(x, y, tree[1], tree[2]);
            if (temp == -1) return -1;
            ans += temp;
            x = tree[1];
            y = tree[2];
        }
        return ans;
    }
    
    int findShortestPath(int x1, int y1, int x2, int y2) {
        if (x1 == x2 && y1 == y2) return 0;
        queue<pair<int, int>> q;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        q.push({x1, y1});
        visited[x1][y1] = true;
        
        int steps = 0;
        while (!q.empty()) {
            int k = q.size();
            steps++;
            while (k--) {
                auto x = q.front().first, y = q.front().second;
                q.pop();
                for (auto &dir: dirs) {
                    int i = x + dir.first, j = y + dir.second;
                    if (i < 0 || j < 0 || i >= m || j >= n || visited[i][j] || !F[i][j]) 
                        continue;
                    if (i == x2 && j == y2) 
                        return steps;
                    visited[i][j] = true;
                    q.push({i, j});
                } 
            }
        }
        return -1;
    }
};
