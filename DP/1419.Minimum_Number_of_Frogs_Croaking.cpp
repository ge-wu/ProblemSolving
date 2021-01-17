class Solution {
public:
    int minNumberOfFrogs(string str) {
        int c = 0, r = 0, o = 0, a = 0;
        int ans = 0;
        for (char s: str) {
            if (s == 'c') {
                c++;
            } else if (s == 'r') {
                c--;
                r++;
                if (c < 0) return -1;
            } else if (s == 'o') {
                r--;
                o++;
                if (r < 0) return -1;
            } else if (s == 'a') {
                o--;
                a++;
                if (o < 0) return -1;
            } else {
                a--;
                if (a < 0) return -1;
            }
            ans = max(ans, c + r + o + a);
        }
        if (c + r + o + a > 0) return -1;
        return ans;
    }
};
