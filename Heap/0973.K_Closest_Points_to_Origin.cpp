typedef pair<int, int> PII;

struct cmp {
    bool operator() (PII &a, PII &b) {
        double dist1 = sqrt(pow(a.first, 2) + pow(a.second, 2));
        double dist2 = sqrt(pow(b.first, 2) + pow(b.second, 2));
        return dist1 > dist2;
    }
};

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        priority_queue<PII, vector<PII>, cmp> pq;
        for (vector<int> &p: points) {
            pq.push(make_pair(p[0], p[1]));
        }
        vector<vector<int>> ans;
        while (K--) {
            auto cur = pq.top();
            pq.pop();
            ans.push_back({cur.first, cur.second});
        }
        return ans;
    }
};
