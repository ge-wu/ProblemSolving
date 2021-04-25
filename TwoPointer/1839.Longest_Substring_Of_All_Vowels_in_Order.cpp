class Solution {
public:
    int longestBeautifulSubstring(string word) {
        int n = word.size();
        if (n < 5) return 0;

        int ans = INT_MIN, i = 0;
        set<char> cnt;
        
        while (i < n) {
            int j = i + 1;
            cnt.clear();
            cnt.insert(word[i]);
            
            while (j < n && word[j - 1] <= word[j]) {
                cnt.insert(word[j++]);
            }
            if (cnt.size() == 5)
                ans = max(ans, j - i);
            i = j;
        }
        return ans == INT_MIN ? 0 : ans;
    }
};
