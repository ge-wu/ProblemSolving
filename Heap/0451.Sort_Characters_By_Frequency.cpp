typedef pair<char, int> PCI;

struct cmp {
    bool operator() (PCI &a, PCI &b) {
        return a.second < b.second;
    }
};

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> cnt;
        for (char c: s) 
            cnt[c]++;
        
        priority_queue<PCI, vector<PCI>, cmp> pq;
        for (auto &it: cnt) {
            pq.push(make_pair(it.first, it.second));
        }
        
        string ans = "";
        while (!pq.empty()) {
            auto cur = pq.top();
            pq.pop();
            ans += string(cur.second, cur.first);
        }
        return ans;
    }
};
