class Solution {
public:
    string customSortString(string order, string str) {
        string ans = "";
        vector<int> cnt(26, 0);
        for (char c: str) {
            ++cnt[c - 'a'];
        }
        for (char c: order) {
            string s(cnt[c - 'a'], c);
            cnt[c - 'a'] = 0;
            ans += s;
        }
        for (int i = 0; i < 26; ++i) {
            char c = i + 'a';
            ans += string(cnt[i], c);
        }
        return ans;
    }
};
