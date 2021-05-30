class Solution {
public:
    int compress(vector<char>& A) {
        int i = 0, j = 0, n = A.size();
        while (i < n) {
            A[j] = A[i];
            int cnt = 0;
            while (i < n && A[j] == A[i]) {
                i++;
                cnt++;
            }
            if (cnt > 1) {
                for (char c: to_string(cnt)) {
                    A[++j] = c;
                }
            }
            j++;
        }
        return j;
    }
};
