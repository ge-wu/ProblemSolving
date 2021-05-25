class Solution {
public:
    int kSimilarity(string s1, string s2) {
        if (s1 == s2) return 0;
        
        int n = s1.size(), k = 0;
        queue<string> q;
        unordered_set<string> seen;
        
        q.push(s1);
        seen.insert(s1);
        
        while (!q.empty()) {
            int len = q.size();
            while (len--) {
                string cur = q.front(); q.pop();
                int i = 0;
                while (i < cur.size() && cur[i] == s2[i])
                    i++;
                for (int j = i + 1; j < cur.size(); j++) {
                    if (cur[i] == s2[j]) {
                        string temp = cur;
                        swap(temp[i], temp[j]);
                        if (temp == s2) 
                            return k + 1;
                        if (!seen.count(temp)) {
                            q.push(temp);
                            seen.insert(temp);
                        }
                    }
                }
            }
            k++;
        }
        return k;
    }
};
