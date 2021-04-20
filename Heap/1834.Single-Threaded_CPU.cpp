typedef pair<int, int> PII;
typedef long long ll;
class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& t) {
        priority_queue<PII, vector<PII>, greater<>> pq;
        ll n = t.size(), cur_time = 0, i = 0;
        for (int i = 0; i < n; i++) {
            t[i].push_back(i);
        }
        sort(t.begin(), t.end());
        vector<int> ans;
        while (i < n || pq.size()) {
            if (pq.empty()) {
                cur_time = max(cur_time, (ll) t[i][0]);
            }
            while (i < n && cur_time >= t[i][0]) {
                pq.push({t[i][1], t[i][2]});
                i++;
            }
            PII cur = pq.top(); pq.pop();
            cur_time += cur.first;
            ans.push_back(cur.second);
        }
        return ans;
    }
};
