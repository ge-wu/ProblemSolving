class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int total = 0, ans = 0;
        sort(costs.begin(), costs.end());
        for (int i = 0; i < costs.size(); i++) {
            total += costs[i];
            if (total > coins) return i;
            ans++;

        }
        return ans;
    }
};
