class Solution {
public:
    vector<vector<int>> ans;
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> cur;
        dfs(cur, graph, 0);
        return ans;
    }
    
    void dfs(vector<int> &cur, vector<vector<int>> &graph, int i) {
        if (find(cur.begin(), cur.end(), i) != cur.end()) 
            return;
        if (i == graph.size() - 1) {
            cur.push_back(i);
            ans.push_back(cur);
            cur.pop_back();
            return;
        }
        for (int next: graph[i]) {
            cur.push_back(i);
            dfs(cur, graph, next);
            cur.pop_back();
        }
    }
};
