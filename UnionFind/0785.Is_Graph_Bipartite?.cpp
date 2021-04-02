class Solution {
public:
    unordered_map<int, int> parents;
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        for (int i = 0; i < n; i++) {
            parents[i] = i;
        }
        for (int i = 0; i < n; i++) {
            int k;
            if (graph[i].size() > 0) {
                k = graph[i][0];
            }
            for (auto j: graph[i]) {
                if (Find(i) == Find(j)) {
                    return false;
                }
                Union(k, j);
            }
        }
        return true;
    }
    
    int Find(int x) {
        if (parents[x] != x) {
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
