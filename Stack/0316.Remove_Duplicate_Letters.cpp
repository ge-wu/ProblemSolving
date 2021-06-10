class Solution {
public:
    string removeDuplicateLetters(string s) {
                int cnt[26] = {}, vis[26] = {}, n = s.size();
        string ans = "";
        for (int i = 1; i < n; ++i) {
            cnt[s[i] - 'a'] = i;
        }
        for (int i = 0; i < n; ++i) {
            if (vis[s[i] - 'a']++) {
                continue;
            }
            while (!ans.empty() && s[i] < ans.back() && i < cnt[ans.back() - 'a']) {
                vis[ans.back() - 'a'] = 0;
                ans.pop_back();
            }
            ans.push_back(s[i]);
        }
        return ans;
    }
};
