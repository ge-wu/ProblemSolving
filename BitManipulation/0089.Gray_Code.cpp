class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ans = {0};
        for (int i = 0; i < n; ++i) {
            int m = ans.size();
            for (int j = m - 1; j >= 0; --j) {
                ans.push_back(ans[j] | (1 << i));
            }
        }
        return ans;
    }
};
