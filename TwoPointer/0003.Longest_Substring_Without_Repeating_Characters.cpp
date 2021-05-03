class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i = 0, j = 0, n = s.size(), ans = 0;
        unordered_map<char, int> cnt;
        while (j < n) {
            if (cnt[s[j]] == 0) {
                cnt[s[j]] = 1;
                j++;
            } else {
                cnt[s[i]] = 0;
                i++;
            }
            ans = max(ans, j - i);
        }
        return ans;
    }
};
