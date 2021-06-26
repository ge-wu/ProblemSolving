class Solution {
public:
    string removeOccurrences(string s, string part) {
        string ans = "";
        int n = part.size();
        for (char c: s) {
            ans += c;
            if (ans.size() >= n) {
                if (ans.substr(ans.size() - n) == part) {
                    ans = ans.substr(0, ans.size() - n);
                }
            }
        }
        return ans;
    }
};
