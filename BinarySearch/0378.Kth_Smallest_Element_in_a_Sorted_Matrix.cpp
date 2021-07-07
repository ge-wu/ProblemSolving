class Solution {
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
        int n = mat.size(), left = INT_MIN / 2, right = INT_MAX / 2;
        while (left < right) {
            int mid = left + (right - left) / 2;
            int temp = 0;
            for (int i = 0; i < n; ++i) {
                int pos = upper_bound(mat[i].begin(), mat[i].end(), mid) - mat[i].begin();
                temp += pos;
            }
            if (temp < k) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }
};
