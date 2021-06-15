class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int> cnt = {0, 0, 0};
        int ans = 0, i = 0, n = s.size();
        for (int j = 0; j < n; ++j) {
            cnt[s[j] - 'a']++;
            while (cnt[0] && cnt[1] && cnt[2]) {
                cnt[s[i++] - 'a']--;
            }
            ans += i;
        }
        return ans;
    }
};
