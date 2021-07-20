class Solution {
public:
    int addRungs(vector<int>& A, int d) {
        A.insert(A.begin(), 0);
        int ans = 0;
        for (int i = 1; i < A.size(); ++i) {
            ans += (A[i] - 1 - A[i - 1]) / d;
        }
        return ans;
    }
};
