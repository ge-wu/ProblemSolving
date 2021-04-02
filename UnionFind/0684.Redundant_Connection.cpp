class Solution {
public:
    unordered_map<int, int> parents;
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        for (int i = 0; i < edges.size(); i++) {
            parents[edges[i][0]] = edges[i][0];
            parents[edges[i][1]] = edges[i][1];
        }
        for (int i = 0; i < edges.size(); i++) {
            if (Find(edges[i][0]) == Find(edges[i][1])) {
                return edges[i];
            } else {
                Union(edges[i][0], edges[i][1]);
            }
        }
        return edges[0];
    }
    int Find(int x) {
        if (x != parents[x])
            parents[x] = Find(parents[x]);
        return parents[x];
    }
    void Union(int x, int y) {
        x = Find(x);
        y = Find(y);
        parents[x] = y;
    }
};
