class Solution {
public:
    unordered_map<int, int> parents;
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        for (auto & stone: stones) {
            int x = stone[0], y = stone[1];
            parents[x * n + y] = x * n + y;
        }
        
        for (int i = 0; i < n; i++) {
            int x = stones[i][0], y = stones[i][1];
            for (int j = 0; j < n; j++) {
                int a = stones[j][0], b = stones[j][1];
                if (x == a || y == b) {
                    if (Find(x * n + y) != Find(a * n + b)) {
                        Union(x * n + y, a * n + b);
                    }
                }
            }
        }
        
        for (auto & stone: stones) {
            int x = stone[0], y = stone[1];
            parents[x * n + y] = Find(x * n + y);
        }
        
        unordered_map<int, int> cnt;
        for (auto & it: parents) {
            cnt[it.second]++;
        }
        
        int ans = 0;
        for (auto & it: cnt) {
            ans += it.second - 1;
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
        parents[x] = y;
    }
};
