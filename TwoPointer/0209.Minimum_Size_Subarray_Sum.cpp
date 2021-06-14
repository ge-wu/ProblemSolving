class Solution {
public:
    int minSubArrayLen(int target, vector<int>& A) {
        int n = A.size(), ans = INT_MAX, i = 0, len = 0;
        for (int j = 0; j < n; ++j) {
            target -= A[j];
            while (target <= 0) {
                ans = min(ans, j - i + 1);
                target += A[i++];
            }
        }
        return ans == INT_MAX ? 0 : ans;
    }
};

