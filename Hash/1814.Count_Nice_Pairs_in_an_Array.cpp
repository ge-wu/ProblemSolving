class Solution {
public:
    int countNicePairs(vector<int>& nums) {
        int mod = 1e9+7, ans = 0;
        unordered_map<int, int> mp;
        for (int num: nums) {
            mp[num - rev(num)]++;
        }
        for (auto &it: mp) {
            long long n = it.second;
            ans += (n * (n - 1) / 2) % mod;
        }
        return ans;
    }
    
    int rev(int num) {
        int ans = 0;
        while (num) {
            ans = ans * 10 + num % 10;
            num /= 10;
        }
        return ans;
    }
};
