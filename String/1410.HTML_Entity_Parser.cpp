class Solution {
public:
    string entityParser(string A) {
        map<string, string> ref = {
            {"&quot", "\""}, {"&apos", "'"}, {"&amp", "&"}, 
            {"&gt", ">"}, {"&lt", "<"}, {"&frasl", "/"}
        };
        int n = A.size(), i = 0;
        string ans = "";
        while (i < n) {
            if (A[i] == '&') {
                string cur = "";
                while (i < n && A[i] != ';' && (i + 1 < n  && A[i+1] != '&')) 
                    cur += A[i++];
                ans += (ref.count(cur)) ? ref[cur] : cur + A[i];
            } else {
                ans += A[i];
            }
            i++;
        }
        return ans;
    }
};
