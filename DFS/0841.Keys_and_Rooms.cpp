class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> visited(rooms.size(), false);
        dfs(0, visited, rooms);
        for (bool v: visited) {
            if (!v) 
                return false;
        }
        return true;
    }
    
    void dfs(int src, vector<bool> &visited, vector<vector<int>> &rooms) {
        if (visited[src]) return;
        visited[src] = true;
        for (int next: rooms[src]) {
            dfs(next, visited, rooms);
        }
    }
};
