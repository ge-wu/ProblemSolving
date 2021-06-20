class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int n = costs.size() / 2, ans = 0;
        sort(costs.begin(), costs.end(), [] (vector<int> &x, vector<int> &y) {
            return x[0] - x[1] < y[0] - y[1];
        });
        for (int i = 0; i < n; ++i) {
            ans += costs[i][0] + costs[i + n][1];
        }        
        return ans;
    }
};
