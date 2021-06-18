class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& A) {
        int m = A.size(), n = A[0].size();
        vector<vector<char>> ans(n, vector<char>(m, '.'));
        for (int i = 0; i < m; ++i) {
            int k = n - 1;
            for (int j = n - 1; j >= 0; --j) {
                if (A[i][j] == '*') {
                    ans[j][m - i - 1] = '*';
                    k = j - 1;
                } else if (A[i][j] == '#') {
                    ans[k--][m - i - 1] = '#';
                }
            }
        }
        return ans;
    }
};
