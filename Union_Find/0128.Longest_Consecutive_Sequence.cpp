class Solution {
public:
    unordered_map<int, int> parents;
    
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if (!n) {
            return 0;
        }
        for (int i = 0; i < n; i++) {
            parents[nums[i]] = nums[i];
        }
        for (int &num: nums) {
            int a = num - 1, b = num + 1;
            if (parents.find(a) != parents.end()) {
                Union(num, a);
            }
            if (parents.find(b) != parents.end()) {
                Union(num, b);
            }
        }
        for (int num: nums) {
            parents[num] = Find(num);
        }
        unordered_map<int, int> cnt;
        for (auto &it: parents) {
            cnt[it.second]++;
        }
        int ans = INT_MIN;
        for (auto &it: cnt) {
            ans = max(ans, it.second);
        }
        return ans;
    }
    
    int Find(int x) {
        if (x != parents[x]) {
            parents[x] = Find(parents[x]);
        }
        return parents[x];
    }
    
    void Union(int x, int y) {
        x = Find(x);
        y = Find(y);
        if (x != y)
            parents[x] = y;
    }
};
