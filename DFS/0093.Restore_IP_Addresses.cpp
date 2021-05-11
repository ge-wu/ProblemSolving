class Solution {
public:
    vector<string> ans;
    
    vector<string> restoreIpAddresses(string s) {
        if (s.size() > 12) return ans;
        vector<int> cur;
        dfs(s, cur);
        return ans;
    }
    
    void dfs(string s, vector<int> &cur, int idx=0) {
        if (cur.size() == 4) {
            string temp = "";
            for (int i = 0; i < cur.size(); i++) {
                temp += to_string(cur[i]);
                if (i != 3) temp += '.';
            }
            if (temp.size() == s.size() + 3) 
                ans.push_back(temp);
            return;
        }
        for (int len = 1; len < 4 && idx + len <= s.size(); len++) {
            int temp = atoi(s.substr(idx, len).c_str());
            if (temp > 255) break;
            cur.push_back(temp);
            dfs(s, cur, idx + len);
            cur.pop_back();
        }
    }
};

