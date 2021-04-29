struct cmp {
    bool operator() (pair<char, int> &a, pair<char, int> &b) {
        return a.second < b.second;
    }
};

class Solution {
public:
    string reorganizeString(string S) {
        unordered_map<char, int> cnt;
        priority_queue<pair<char, int>, vector<pair<char, int>>, cmp> pq;
        for (char c: S) cnt[c]++;
        for (auto &it: cnt) {
            pq.push({it.first, it.second});
        }
        string ans = "";
        while (!pq.empty()) {
            auto temp = pq.top(); pq.pop();
            if (temp.second == 0) continue;
            if (!ans.size() || ans.back() != temp.first) {
                ans.push_back(temp.first);
                pq.push({temp.first, temp.second - 1});
            } else {
                auto temp2 = pq.top(); pq.pop();
                if (temp2.first == ans.back()) return "";
                ans.push_back(temp2.first);
                pq.push({temp2.first, temp2.second - 1});
                pq.push(temp);
            }
        }
        
        return ans;
    }
};
