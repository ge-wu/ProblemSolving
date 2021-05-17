class Solution {
public:
    int minSwaps(string s) {
        int x = 0, y = 0;
        for (char c: s) {
            if (c == '1') x++;
            else y++;
        }
        if (abs(x - y) > 1) return -1;
        
        if (x == y)
            return min(helper(s, '0'), helper(s, '1'));
        else if (x > y) 
            return helper(s, '1');
        else
            return helper(s, '0');
    }
    
    int helper(string s, char c) {
        int ans = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != c) ans++;
            c ^= 1;
        }
        return ans / 2;
    }
};
