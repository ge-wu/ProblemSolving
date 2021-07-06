struct cmp {
    bool operator() (pair<int, int> a, pair<int, int> b) {
        return a.second < b.second;
    }
};

class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int, int> cnt;
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
        int ans = 0, n = arr.size(), curSize = 0;
        for (int a: arr) {
            cnt[a]++;
        }
        for (auto it: cnt) {
            pq.push({it.first, it.second});
        }
        while (!pq.empty()) {
            auto cur = pq.top();
            pq.pop();
            ans++;
            curSize += cur.second;
            if (curSize >= n / 2) {
                return ans;
            }
        }
        return ans;
    }
};
