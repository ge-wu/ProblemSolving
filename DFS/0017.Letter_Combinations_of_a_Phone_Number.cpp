class Solution {
public:
    vector<string> ref = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> ans;
    
    vector<string> letterCombinations(string digits) {
        if (!digits.size()) return ans;
        dfs(0, digits, "");
        return ans;
    }
    
    void dfs(int k, string digits, string cur) {
        if (k == digits.size()) {
            ans.push_back(cur);
            return;
        }
        
        for (char c: ref[digits[k] - '0']) {
            cur.push_back(c);
            dfs(k + 1, digits, cur);
            cur.pop_back();
        }
    }
};
