class Solution {
public:
    set<int> s;
    vector<int> numsSameConsecDiff(int n, int k) {
        for (int i = 1; i < 10; i++) {
            dfs(i, n - 1, k);
        }
        vector<int> ans(s.begin(), s.end());
        return ans;
    }

    void dfs(int num, int n, int k) {
        if (!n) {
            s.insert(num);
            return;
        }
        int last = num % 10;
        int a = last + k, b = last - k;
        if (a < 10)
            dfs(num * 10 + a, n - 1, k);
        if (b >= 0) 
            dfs(num * 10 + b, n - 1, k);
    }
};
