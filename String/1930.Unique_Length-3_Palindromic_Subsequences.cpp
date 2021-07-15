class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int ans = 0;
        for (char c = 'a'; c <= 'z'; ++c) {
            int i = s.find(c), j = s.find_last_of(c);
            if (i > -1 && j > i) {
                ans += unordered_set<char>(s.begin() + i + 1, s.begin() + j).size();
            }
        }
        return ans;
    }
};
