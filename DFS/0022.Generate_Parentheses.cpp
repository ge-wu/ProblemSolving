class Solution {
public:
    vector<string> ans;
    vector<string> generateParenthesis(int n) {
        dfs("", n, n);
        return ans;
    }
    
    void dfs(string cur, int open, int close) {
        if (!close) {
            ans.push_back(cur);
            return;
        }
        if (open) {
            dfs(cur + "(", open - 1, close);
        }
        if (close > open) {
            dfs(cur + ")", open, close - 1);
        }
    }
};
