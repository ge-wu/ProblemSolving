typedef pair<int, int> PII;

struct cmp {
    bool operator() (PII &a, PII &b) {
        return abs(a.first - a.second) < abs(b.first - b.second);
    }
};

class Solution {
public:
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
        priority_queue<PII, vector<PII>, cmp> pq;
        int n = nums2.size();
        for (int i = 0; i < n; i++) {
            if (nums1[i] == nums2[i]) continue;
            pq.push({nums1[i], nums2[i]});
        }
                
        if (pq.empty()) return 0;
        
        PII temp = pq.top(); pq.pop();
        int a = temp.first, b = temp.second;
        int replace = abs(b - a);
        for (int i = 0; i < n; i++) {
            if (abs(b - nums1[i]) < replace) {
                replace = abs(b - nums1[i]);
                a = nums1[i];
            }
        }
        
        int ans = abs(b - a), mod = 1000000007;
        while (!pq.empty()) {
            auto cur = pq.top(); pq.pop();
            ans = (ans + abs(cur.first - cur.second)) % mod;
        }
        return ans;
    }
};
