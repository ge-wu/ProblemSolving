class Solution {
public:
    vector<int> parents;
    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        parents.resize((n + 1) * (n + 1));
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= n; j++) {
                int id = i * (n + 1) + j;
                parents[id] = id;
                if (i == 0 || j == 0 || i == n || j == n) {
                    parents[id] = 0;
                }
            }
        }
        int ans = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == ' ') {
                    continue;
                }
                int a, b;
                if (grid[i][j] == '/') {
                    a = i * (n + 1) + j + 1;
                    b = (i + 1) * (n + 1) + j;
                } else {
                    a = i * (n + 1) + j;
                    b = (i + 1) * (n + 1) + (j + 1);
                }
                if (Find(a) == Find(b)) {
                    ans++;
                } else {
                    Union(a, b);
                }
            }
        }
        return ans;
    }
    
    int Find(int x) {
        if (x != parents[x]) {
            parents[x] = Find(parents[x]);
        }
        return parents[x];
    }
    
    void Union(int x, int y) {
        x = Find(x);
        y = Find(y);
        parents[x] = y;
    }
};
