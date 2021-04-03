class Solution {
public:    
    string countAndSay(int n) {
        if (n == 1) return "1";
        return helper(countAndSay(n - 1));
    }
    
    string helper(string str) {
        int i;
        string ans = "";
        vector<int> cnt(10, 0);
        
        cnt[str[0]-'0']++;
        for (i = 1; i < str.size(); i++) {
            cnt[str[i]-'0']++;
            if (str[i] != str[i-1]) {
                ans += to_string(cnt[str[i-1]-'0']) + str[i-1];
                cnt[str[i-1]-'0'] = 0;
            }
        }
        ans += to_string(cnt[str[i-1]-'0']) + str[i-1];
        return ans;
    }
};
