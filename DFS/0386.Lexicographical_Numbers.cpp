class Solution {
public:
    vector<int> ans;
    vector<int> lexicalOrder(int n) {
        for (int i = 1; i < 10; ++i) {
            dfs(i, n);
        }
        return ans;
    }
    void dfs(int cur, int n) {
        if (cur > n) {
            return;
        }
        ans.push_back(cur);
        for (int i = 0; i < 10; ++i) {
            dfs(cur * 10 + i, n);
        }
    }
};
