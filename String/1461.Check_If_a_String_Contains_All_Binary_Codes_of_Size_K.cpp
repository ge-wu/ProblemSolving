class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int need = 1 << k, n = s.size();
        set<string> cnt;
        for (int i = 0; i < max(0, n - k + 1); i++) {
            string cur = s.substr(i, k);
            if (cnt.find(cur) == cnt.end()) {
                cnt.insert(cur);
                need--;
                if (need == 0) return true;
            }
        }
        return false;
    }
};
