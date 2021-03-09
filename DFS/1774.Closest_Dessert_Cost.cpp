class Solution {
public:
    int ans;
    int closestCost(vector<int>& baseCosts, vector<int>& toppingCosts, int target) {
        int ans = baseCosts[0];
        for (int b: baseCosts) {
            dfs(0, toppingCosts, b, ans, target);
        }
        return ans;
    }
    
    void dfs(int i, vector<int>& topping, int sum, int &ans, int target) {
        if (i == topping.size()) {
            if (abs(sum - target) < abs(ans - target)) {
                ans = sum;
            }
            if (abs(sum - target) == abs(ans - target) && sum < ans) {
                ans = sum;
            }
            return;
        }
        dfs(i + 1, topping, sum, ans, target);
        dfs(i + 1, topping, sum + topping[i], ans, target);
        dfs(i + 1, topping, sum + 2 * topping[i], ans, target);
    }
};
