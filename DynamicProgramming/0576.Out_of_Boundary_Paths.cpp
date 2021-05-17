#define ll long long

class Solution {
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<ll>> arr(m, vector<ll>(n, 0));
        while (maxMove--) {
            vector<vector<ll>> w = arr;
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    ll up = i - 1 < 0 ? 1 : arr[i - 1][j];
                    ll down = i + 1 >= m ? 1 : arr[i + 1][j];
                    ll right = j + 1 >= n ? 1 : arr[i][j + 1];
                    ll left = j - 1 < 0 ? 1 : arr[i][j - 1];
                    w[i][j] = (up + down + right + left) % 1000000007;
                }
            }
            arr = w;
        }
        return arr[startRow][startColumn];
    }
};
