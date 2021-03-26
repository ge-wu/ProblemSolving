class Solution {
public:
    vector<string> wordSubsets(vector<string>& A, vector<string>& B) {
        vector<int> cnt(26, 0);
        vector<string> ans;
        set<string> setB(begin(B), end(B));
        
        for (string b: setB) {
            vector<int> temp = count(b);
            for (int i = 0; i < 26; i++) {
                cnt[i] = max(cnt[i], temp[i]);
            }
        }
        for (string a: A) {
            vector<int> temp = count(a);
            bool ok = true;
            for (int i = 0; i < 26; i++) {
                if (temp[i] < cnt[i]) {
                    ok = false;
                    break;
                }
            }
            if (ok) ans.push_back(a);
        }
        return ans;
    }
    
    vector<int> count(string word) {
        vector<int> cnt(26, 0);
        for (char c: word) cnt[c - 'a']++;
        return cnt;
    }
};
