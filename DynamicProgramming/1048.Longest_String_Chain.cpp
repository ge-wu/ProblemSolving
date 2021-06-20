class Solution {
public:
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), [] (string a, string b) {
            return a.size() < b.size();
        });
        unordered_map<string, int> dp;
        int ans = INT_MIN;
        for (string w: words) {
            for (int i = 0; i< w.size(); ++i) {
                string temp = w.substr(0, i) + w.substr(i + 1);
                dp[w] = max(dp[w], dp.find(temp) != dp.end() ? dp[temp] + 1 : 1);
            }
            ans = max(ans, dp[w]);
        }
        return ans;
    }
};
