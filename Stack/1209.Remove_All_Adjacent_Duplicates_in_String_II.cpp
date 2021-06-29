class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char, int>> stk;
        for (char c: s) {
            if (stk.empty() || stk.top().first != c) {
                stk.push({c, 1});
            } else {
                auto temp = stk.top();
                stk.pop();
                if (++temp.second < k) {
                    stk.push(temp);
                }
            }
        }
        string ans = "";
        while (!stk.empty()) {
            auto cur = stk.top();
            stk.pop();
            string s(cur.second, cur.first);
            ans = s + ans;
        }
        return ans;
    }
};
