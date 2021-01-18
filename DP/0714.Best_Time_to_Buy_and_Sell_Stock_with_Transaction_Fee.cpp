class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int hold = -50001, sold = 0;
        for (int i = 0; i < prices.size(); i++) {
            int h = hold, s = sold;
            hold = max(h, sold - prices[i]);
            sold = max(h + prices[i] - fee, s);
        }
        return max(hold, sold);
    }
};
