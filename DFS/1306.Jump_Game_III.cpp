class Solution {
public:
    vector<int> w;
    vector<bool> visited;
    int n;
    bool canReach(vector<int>& arr, int start) {
        w = arr;
        n = w.size();
        visited = vector<bool>(n, false);
        return dfs(start);
    }
    
    bool dfs(int x) {
        if (x < 0 || x >= n || visited[x]) 
            return false;
        if (!w[x]) 
            return true;
        visited[x] = true;
        bool temp = dfs(x + w[x]) || dfs(x - w[x]);
        visited[x] = false;
        return temp;
    }
};
