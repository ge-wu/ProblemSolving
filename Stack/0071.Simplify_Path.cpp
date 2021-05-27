class Solution {
public:
    string simplifyPath(string path) {
        int i = 0, n = path.size();
        vector<string> stk;
        
        while (i < n) {
            string cur = "";
            while (i < n && path[i] != '/')
                cur += path[i++];
            i++;
            if (cur == "" || cur == ".") {
                continue;
            } else if (cur == "..") {
                if (!stk.empty()) 
                    stk.pop_back();
            } else {
                stk.push_back(cur);
            }
        }
        string ans = "";
        for (int i = 0; i < stk.size(); i++) {
            ans += stk[i];
            if (i != stk.size() - 1) 
                ans += "/";
        }
        return "/" + ans;
    }
};
