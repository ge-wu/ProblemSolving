typedef long long ll;

class Solution {
public:
    ll powerMod(ll a, ll b, ll mod) {
        a %= mod;
        long long ans = 1;
        while (b) {
            if (b % 2 == 1) ans = (ans * a) % mod;
            a = (a * a) % mod;
            b >>= 1;
        }
        return (int) ans;
    }
    
    int maxNiceDivisors(int p) {
        if (p == 1) return 1;
        int d = p / 3, r = p % 3, mod = 1000000000 + 7;
        if (r == 1) {
            d--;
            r = 2;
        } else if (r == 2) {
            r = 1;
        }
        return powerMod(2, r, mod) * powerMod(3, d, mod) % mod;
    }
};
