class Solution {
    typedef pair<int, int> PII;
public:    
    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<PII>> graph;
        for (auto &edge: edges) {
            graph[edge[0]].push_back({edge[1], edge[2]});
            graph[edge[1]].push_back({edge[0], edge[2]});
        }
        
        vector<int> dist(n + 1, INT_MAX);
        priority_queue<PII, vector<PII>, greater<PII>> pq;
        pq.push({0, n});
        dist[n] = 0;
        
        while (!pq.empty()) {
            PII cur = pq.top();
            pq.pop();
            int curNode = cur.second;
            for (auto [next, d]: graph[curNode]) {
                if (dist[next] > dist[curNode] + d) {
                    dist[next] = dist[curNode] + d;
                    pq.push({dist[next], next});
                }
            }
        }
        vector<int> memo(n + 1, -1);
        return DFS(n, graph, dist, memo);
    }
    
    int DFS(int n, unordered_map<int, vector<pair<int, int>>> &graph, 
            vector<int> &dist, vector<int> &memo) {
        if (memo[n] != -1) return memo[n];
        if (n == 1) return 1;
        int ans = 0;
        for (auto [next, d]: graph[n]) {
            if (dist[next] > dist[n]) {
                ans = (ans + DFS(next, graph, dist, memo)) % (1000000007);
            }
        }
        return memo[n] = ans;
    }
};
