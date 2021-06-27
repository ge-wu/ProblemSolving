typedef long long ll;

class Solution {
public:
    ll wonderfulSubstrings(string word) {
        ll ans = 0, mask = 0, cnt[1024] = {};
        cnt[0] = 1;
        for (char c: word) {
            mask ^= 1 << (c - 'a');
            ans += cnt[mask]++;
            for (int i = 0; i < 10; ++i) {
                ans += cnt[mask ^ (1 << i)];
            }
        }
        return ans;
    }
};
