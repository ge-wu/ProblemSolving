typedef vector<vector<int>> VII;

class Solution {
public:
    vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if (!m) return {};
        int n = matrix[0].size();
        
        VII pac(m, vector<int>(n, 0));
        VII atl(m, vector<int>(n, 0));
        for (int i = 0; i < n; i++) dfs(0, i, matrix, pac);
        for (int i = 1; i < m; i++) dfs(i, 0, matrix, pac);
        for (int i = 0; i < n; i++) dfs(m - 1, i, matrix, atl);
        for (int i = 0; i < m - 1; i++) dfs(i, n - 1, matrix, atl);
        
        VII ans;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (atl[i][j] == 1 && pac[i][j] == 1) 
                    ans.push_back({i, j});
            }
        }
        return ans;
    }
    
    void dfs(int i, int j, VII &mat, VII &visited) {
        for (auto [a, b]: dirs) {
            visited[i][j] = 1;
            int x = i + a, y = j + b;
            if (x < 0 || y < 0 || x >= mat.size() || y >= mat[0].size()) 
                continue;
            if (visited[x][y]) 
                continue;
            if (mat[x][y] < mat[i][j]) 
                continue;
            dfs(x, y, mat, visited);
        }
    } 
};
