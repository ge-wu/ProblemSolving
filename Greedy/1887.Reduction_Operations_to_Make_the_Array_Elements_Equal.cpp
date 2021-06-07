class Solution {
public:
    int reductionOperations(vector<int>& A) {
        map<int, int> mp;
        for (int a: A) {
            mp[a]++;
        }
        int ans = 0, prev = 0;
        for (auto it = mp.end(); it != mp.begin(); --it) {
            ans += prev + it->second;
            prev += it->second;
        }
        return ans;
    }
};
