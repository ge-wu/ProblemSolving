class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        long long total = 0;
        for (int shift: shifts) {
            total += shift;
        }
        string ans = "";
        for (int i = 0; i < s.size(); ++i) {
            char c = (char) ((s[i] - 'a' + 26 + total) % 26 + 97);
            ans += string(1, c);
            total -= shifts[i];
        }
        return ans;
    }
};
