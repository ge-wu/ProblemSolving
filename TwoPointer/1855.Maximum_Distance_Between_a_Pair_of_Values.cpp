class Solution {
public:
    int maxDistance(vector<int>& A, vector<int>& B) {
        int i = A.size() - 1, j = B.size() - 1;
        int ans = 0;
        while (i >= 0 && j >= 0) {
            int a = A[i], b = B[j];
            if (b >= a) {
                i--;
                ans = max(ans, j - i - 1);
            } else j--;
        }
        return ans;
    }
};
