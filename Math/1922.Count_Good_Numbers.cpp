#define ll long long
#define mod 1000000007

class Solution {
public:
    int countGoodNumbers(ll n) {
        ll x = ceil(1.0 * n / 2), y = n / 2;
        ll a = fastPower(5, x), b = fastPower(4, y);
        return (a * b) % mod;
    }

    int fastPower(ll b, ll p) {
        ll ans = 1;
        while (p) {
            if (p & 1) {
                ans = (ans * b) % mod;
            }
            b = (b * b) % mod;
            p /= 2;
        }
        return ans;
    }
};
