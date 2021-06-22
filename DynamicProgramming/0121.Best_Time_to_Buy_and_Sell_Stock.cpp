class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2) {
            return 0;
        }
        int sell = 0, dont_cell = prices[0];
        for (int i = 1; i < prices.size(); ++i) {
            if (prices[i] > prices[i - 1]) {
                sell = max(sell, prices[i] - sell);
            } else {
                dont_cell = min(dont_cell, prices[i]);
            }
        }
        return sell;
    }
};
