class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int, vector<int>, greater<int>> pq;
        int totalBricks = 0;
        for (int i = 1; i < heights.size(); i++) {
            int temp = heights[i] - heights[i - 1];
            if (temp <= 0) continue;
            pq.push(temp);
            if (pq.size() > ladders) {
                totalBricks += pq.top();
                pq.pop();
            }
            if (totalBricks > bricks) return i - 1;
        }
        return heights.size() - 1;
    }
};
