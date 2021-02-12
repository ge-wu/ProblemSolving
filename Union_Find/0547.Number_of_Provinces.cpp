class Solution {
public:
    unordered_map<int, int> parents;
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        for (int i = 1; i <= n; i++) 
            parents[i] = i;
        
        for (int i = 0; i < n; i++) 
            for (int j = i; j < n; j++) 
                if (isConnected[i][j] && Find(i) != Find(j)) 
                    Union(i, j);
        
        unordered_set<int> ans;
        for (int i = 0; i < n; i++) {
            parents[i] = Find(i);
            ans.insert(parents[i]);
        }
        return ans.size();
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
