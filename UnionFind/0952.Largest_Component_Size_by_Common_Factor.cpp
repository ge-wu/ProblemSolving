class Solution {
public:
    vector<int> p;
    
    int largestComponentSize(vector<int>& nums) {
        int n = *max_element(nums.begin(), nums.end());
        for (int i = 0; i <= n; i++) p.push_back(i);
        for (int num: nums) {
            for (int i = 2; i <= sqrt(num); i++) {
                if (num % i == 0) {
                    Union(num, i);
                    Union(num, num / i);
                }
            }
        }
        unordered_map<int, int> cnt;
        int ans = INT_MIN;
        for (int num: nums) {
            ans = max(ans, ++cnt[Find(num)]);
        }
        return ans;
    }
    
    int Find(int x) {
        if (p[x] != x) 
            p[x] = Find(p[x]);
        return p[x];
    }
    
    void Union(int x, int y) {
        p[Find(x)] = Find(y);
    }
};
