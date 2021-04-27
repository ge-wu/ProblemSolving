class Solution {
public:
    int candy(vector<int>& A) {
        int n = A.size();
        vector<int> x(n, 1), y(n, 1);
        for (int i = 1; i < n; i++) {
            if (A[i] > A[i-1]) {
                x[i] = x[i-1] + 1;
            }
        }
        for (int i = n - 2; i >= 0; i--) {
            if (A[i] > A[i+1]) {
                y[i] = y[i+1] + 1;
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans += max(x[i], y[i]);
        }
        return ans;
    }
};
