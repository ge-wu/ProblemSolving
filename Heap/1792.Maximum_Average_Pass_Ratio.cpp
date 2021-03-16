typedef pair<int, int> PII;

struct cmp {
    bool operator() (PII &arr1, PII &arr2) {
        double a1 = arr1.first, b1 = arr1.second;
        double a2 = arr2.first, b2 = arr2.second;
        double x = (a1 + 1) / (b1 + 1) - (a1 / b1);
        double y = (a2 + 1) / (b2 + 1) - (a2 / b2);
        return x < y;
    }
};

class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<PII , vector<PII>, cmp> pq;
        for (auto c: classes) {
            pq.push(make_pair(c[0], c[1]));
        }
        
        while (extraStudents--) {
            auto cur = pq.top();
            pq.pop();
            cur.first++;
            cur.second++;
            pq.push(cur);
        }
        
        double ans = 0;
        while (!pq.empty()) {
            auto cur = pq.top();
            pq.pop();
            ans += ((double) cur.first / cur.second);
        }
        return ans / classes.size();
    }
};
