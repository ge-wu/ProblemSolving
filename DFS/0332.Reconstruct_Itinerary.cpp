class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        vector<string> ans;
        unordered_map<string, priority_queue<string, vector<string>, greater<>>> mp;
        for (auto &t: tickets) {
            mp[t[0]].push(t[1]);
        }
        stack<string> s;
        s.push("JFK");
        while (!s.empty()) {
            string cur = s.top();
            if (mp.find(cur) != mp.end() && !mp[cur].empty()) {
                string next = mp[cur].top();
                mp[cur].pop();
                s.push(next);
            } else {
                ans.push_back(s.top());
                s.pop();
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
