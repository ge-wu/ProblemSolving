class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& A) {
        A.push_back({1, 0});
        sort(A.begin(), A.end());
        int m = A.size();
        vector<int> h(m), p(m), l(m);
        for (int i = 0; i < m; i++) {
            p[i] = A[i][0];
            l[i] = A[i][1];
        }
        h[0] = 0;
        for (int i = 1; i < m; i++) {
            h[i] = min(l[i], h[i-1]+p[i]-p[i-1]);
        }
        for (int i = m - 2; i >= 1; i--) {
            h[i] = min(h[i], h[i+1]+p[i+1]-p[i]);
        }
        int ans = 0;
        for (int i = 1; i < m; i++) {
            int peak = h[i] + (h[i-1]-h[i]-p[i-1]+p[i]) / 2;
            ans = max(ans, peak);
        }
        ans = max(ans, h[m-1]+n-p[m-1]);
        return ans;
    }
};

