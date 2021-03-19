typedef pair<int, int> PII;

struct cmp {
    bool operator() (PII &a, PII &b) {
        return a.second < b.second;
    }
};

class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        unordered_map<int, int> cnt;
        priority_queue<PII, vector<PII>, cmp> pq;
        
        for (int i: barcodes) 
            cnt[i]++;
        for (auto &it: cnt) 
            pq.push(make_pair(it.first, it.second));
            
        vector<int> ans;
        while (!pq.empty()) {
            auto cur = pq.top(); pq.pop();
            if (cur.second <= 0)
                continue;
            if (ans.size() && ans.back() == cur.first) {
                auto next = pq.top(); pq.pop();
                ans.push_back(next.first);
                next.second--;
                pq.push(next);
            } else {
                cur.second--;
                ans.push_back(cur.first);
            }
            pq.push(cur);
        }
        return ans;
    }
};
