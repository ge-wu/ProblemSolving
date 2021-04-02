class Solution {
public:
    vector<int> parents;
    
    int minSwapsCouples(vector<int>& row) {
        int n = row.size();
        parents.resize(n);
        for (int i = 0; i < n; i+=2) {
            parents[i] = i;
            parents[i + 1] = i;
        }
        for (int i = 0; i < n; i+=2) {
            int a = row[i], b = row[i + 1];
            if (Find(a) != Find(b)) {
                Union(a, b);
            }
        }
        unordered_map<int, int> cnt;
        for (int i = 0; i < n; i++) {
            cnt[Find(i)] += 1;
        }
        int ans = 0;
        for (auto & it: cnt) {
            ans += it.second / 2 - 1;
        }
        return ans;
    }
    
    int Find(int x) {
        if (x != parents[x]) 
            parents[x] = Find(parents[x]);
        return parents[x];
    }
    
    void Union(int x, int y) {
        x = parents[x];
        y = parents[y];
        if (x < y)
            parents[y] = x;
        else 
            parents[x] = y;
    }
};
