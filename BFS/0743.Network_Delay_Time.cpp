class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, vector<pair<int, int>>> graph;
        for (auto & time: times) {
            graph[time[0]].push_back({time[1], time[2]});
        }
        
        vector<int> dist(n + 1, INT_MAX);
        vector<bool> visited(n + 1, false);
        dist[k] = 0;
        
        while (true) {
            int curDist = INT_MAX, curNode = -1;
            for (int i = 1; i <= n; i++) {
                if (!visited[i] && dist[i] < curDist) {
                    curNode = i;
                    curDist = dist[i];
                }
            }
            if (curNode == -1) 
                break;
            visited[curNode] = 1;
            for (auto [next, d]: graph[curNode]) {
                dist[next] = min(dist[next], dist[curNode] + d);
            }
        }
        
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            ans = max(ans, dist[i]);
        }
        return ans == INT_MAX ? -1 : ans;
    }
};
