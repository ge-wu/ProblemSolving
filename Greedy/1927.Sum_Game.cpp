class Solution {
public:
    bool sumGame(string num) {
        int n = num.size(), cnt = 0, diff = 0;
        for (int i = 0; i < n; ++i) {
            if (num[i] == '?') {
                cnt += i < n / 2 ? 1 : -1;
            } else {
                diff += i < n / 2 ? (num[i] - '0') : -(num[i] - '0');
            }
        }
        if (cnt & 1) {
            return true;
        }
        return 9 * abs(cnt) / 2 != abs(diff);
    }
};
