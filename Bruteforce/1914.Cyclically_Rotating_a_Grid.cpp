class Solution {
public:
    vector<vector<int>> w;
    
    vector<vector<int>> rotateGrid(vector<vector<int>>& A, int k) {
        w = A;
        int m = A.size() - 1, n = A[0].size() - 1, x = 0, y = 0;
        while (x < m && y < n) {
            vector<int> cur = helper(x, m, y, n);
            rotate(cur.begin(), cur.begin() + (k % cur.size()), cur.end());
            updateMat(cur, x, m, y, n);
            x++, m--, y++, n--;
        }
        return w;
    }
    vector<int> helper(int up, int down, int left, int right) {
        vector<int> ans;
        for (int i = left; i < right; ++i) {
            ans.push_back(w[up][i]);
        }
        for (int i = up; i < down; ++i) {
            ans.push_back(w[i][right]);
        }
        for (int i = right; i >= left; --i) {
            ans.push_back(w[down][i]);
        }
        for (int i = down - 1; i > up; --i) {
            ans.push_back(w[i][left]);
        }
        return ans;
    }
    
    void updateMat(vector<int> &arr, int up, int down, int left, int right) {
        int idx = 0;
        for (int i = left; i < right; ++i) {
            w[up][i] = arr[idx++];
        }
        for (int i = up; i < down; ++i) {
            w[i][right] = arr[idx++];
        }
        for (int i = right; i >= left; --i) {
            w[down][i] = arr[idx++];
        }
        for (int i = down - 1; i > up; --i) {
            w[i][left] = arr[idx++];
        }
    }
};
