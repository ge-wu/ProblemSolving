class Solution {
public:
    double knightProbability(int N, int K, int r, int c) {
        vector<vector<double>> dp(N, vector<double>(N, 0));
        vector<pair<int, int>> knightMove = {
            {-2, -1}, {-1, -2}, {-2, 1}, {-1, 2}, {1, -2}, {2, -1}, {1, 2}, {2, 1}
        };
        dp[r][c] = 1;
        
        for (int k = 0; k < K; k++) {
            vector<vector<double>> tempDP(N, vector<double>(N, 0));
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    for (auto it: knightMove) {
                        int x = it.first + i, y = it.second + j;
                        if (x >= 0 && x < N && y >= 0 && y < N) {
                            tempDP[y][x] += dp[i][j];
                        }
                    }
                }
            }
            swap(dp, tempDP);
        }
        double total = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                total += dp[i][j];
            }
        }
        return total / pow(8, K);
    }
};
