class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
        for (string word: words) {
            if (helper(word, pattern)) 
                ans.push_back(word);
        }
        return ans;
    }
    
    bool helper(string s, string t) {
        unordered_map<char, char> x, y;
        for (int i = 0; i < s.size(); i++) {
            x[s[i]] = t[i];
            y[t[i]] = s[i];
        }
        for (int i = 0; i < s.size(); i++) {
            if (x[s[i]] != t[i] || y[t[i]] != s[i])
                return false;
        }
        return true;
    }
};
