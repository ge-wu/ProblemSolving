typedef pair<int, int> PII;

struct cmp {
    bool operator() (PII &a, PII &b) {
        return a.second < b.second;
    }
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> cnt;
        for (int num: nums) 
            cnt[num]++;
        
        priority_queue<PII, vector<PII>, cmp> pq;
        for (auto &it: cnt) 
            pq.push(make_pair(it.first, it.second));
        
        vector<int> ans;
        while (k--) {
            auto cur = pq.top();
            pq.pop();
            ans.push_back(cur.first);
        }
        return ans;
    }
};
