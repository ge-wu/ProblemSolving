class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size(), left = 0;
        queue<int> q;
        vector<int> visited(n, false);
        q.push(0);
        
        while (!q.empty()) {
            int cur = q.front(); q.pop();
            int x = cur + minJump, y = min(n - 1, cur + maxJump);
            for (int j = max(x, left + 1); j <= y; j++) {
                if (s[j] == '0' && !visited[j]) {
                    if (j == n - 1) return true;
                    visited[j] = true;
                    q.push(j);
                }
            }
            left = max(left, y);
        }
        return false;
    }
};
