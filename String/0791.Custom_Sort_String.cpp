class Solution {
public:
    string customSortString(string order, string str) {
        int cnt[26] = {};
        for (char c: str) {
            cnt[c - 'a']++;
        }
        string ans = "";
        for (char c: order) {
            string s(cnt[c - 'a'], c);
            cnt[c - 'a'] = 0;
            ans += s;
        }
        for (int i = 0; i < 26; ++i) {
            string s(cnt[i], char(i + 'a'));
            ans += s;
        }
        return ans;
    }
};
