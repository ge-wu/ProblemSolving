class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        queue<int> q;
        vector<bool> visited(n, false);
        q.push(start);
        visited[start] = true;
        
        while (!q.empty()) {
            int cur = q.front(); q.pop();
            int a = cur + arr[cur], b = cur - arr[cur];
            if ((a < n && arr[a] == 0) || (b >= 0 && arr[b] == 0)) 
                return true;
            if (a < n && !visited[a]) {
                visited[a] = true;
                q.push(a);
            }
            if (b >= 0 && !visited[b]) {
                visited[b] = true;
                q.push(b);
            }
        }
        return false;
    }
};
