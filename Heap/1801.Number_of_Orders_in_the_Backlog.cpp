typedef pair<int, int> PII;


struct bigger {
    bool operator() (PII &a, PII &b) {
        return a.first < b.first;
    }
};

struct smaller {
    bool operator() (PII &a, PII &b) {
        return a.first > b.first;
    }
};

class Solution {
public:
    int getNumberOfBacklogOrders(vector<vector<int>>& orders) {
        priority_queue<PII, vector<PII>, bigger> buy;
        priority_queue<PII, vector<PII>, smaller> sell;
        for (auto order: orders) {
            if (order[2] == 1) sell.push({order[0], order[1]});
            else buy.push({order[0], order[1]});

            while (!sell.empty() && !buy.empty()) {
                auto b = buy.top(), s = sell.top();
                if (s.first <= b.first) {
                    buy.pop();
                    sell.pop();
                    int x = s.second, y = b.second;
                    s.second = max(0, x - y);
                    b.second = max(0, y - x);
                    if (s.second != 0) sell.push(s);
                    if (b.second != 0) buy.push(b);
                } else {
                    break;
                }
            }
        }
        long long ans = 0;
        while (!sell.empty()) {
            auto cur = sell.top(); sell.pop();
            ans += cur.second;
        }
        while (!buy.empty()) {
            auto cur = buy.top(); buy.pop();
            ans += cur.second;
        }
        
        return ans % 1000000007;
    }
};
