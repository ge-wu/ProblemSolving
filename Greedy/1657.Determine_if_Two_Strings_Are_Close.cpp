class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        if (n != m) {
            return false;
        }
        vector<int> cnt1(26, 0), cnt2(26, 0);
        for (int i = 0; i < n; i++) {
            cnt1[word1[i] - 'a']++;
            cnt2[word2[i] - 'a']++;
        }
        string x = "", y = "";
        for (int i = 0; i < 26; i++) {
            if ((!cnt1[i] && cnt2[i]) || (!cnt2[i] && cnt1[i])) {
                return false;
            }
            x += to_string(cnt1[i]);
            y += to_string(cnt2[i]);
        }
        sort(x.begin(), x.end());
        sort(y.begin(), y.end());
        return x == y;
    }
};
