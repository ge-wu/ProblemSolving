typedef pair<int, int> PII;

struct cmp {
    bool operator() (PII &a, PII &b) {
        return (a.first + a.second) > (b.first + b.second);
    }
};

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<PII, vector<PII>, cmp> pq;
        for (int i = 0; i < nums1.size(); i++) {
            for (int j = 0; j < nums2.size(); j++) {
                pq.push(make_pair(nums1[i], nums2[j]));
            }
        }
        vector<vector<int>> ans;
        while (k-- && !pq.empty()) {
            auto cur = pq.top();
            ans.push_back({cur.first, cur.second});
            pq.pop();
        }
        return ans;
    }
};
