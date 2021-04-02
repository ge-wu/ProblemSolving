class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        int hold = -10000000, sold = 0;
        for (int i = 0; i < n; i++) {
            int h = hold, s = sold;
            hold = max(h, sold - prices[i]);
            sold = max(h + prices[i] - fee, s);
        }
        return sold;
    }
};
