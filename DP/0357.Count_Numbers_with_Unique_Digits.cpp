class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (!n) return 1;
        int ans = 10, cnt = 9;
        for (int i = 2; i <= n; i++) {
            cnt *= 9 - i + 2;
            ans += cnt;
        }
        return ans;
    }
};
