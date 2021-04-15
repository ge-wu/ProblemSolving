class Solution {
public:
    set<string> visited;
    vector<string> w;
    
    int numSimilarGroups(vector<string>& strs) {
        w = strs;
        int ans = 0;
        for (string str: strs) {
            if (!visited.count(str)) {
                visited.insert(str);
                dfs(str);
                ans++;
            }
        }
        return ans;
    }
    
    void dfs(string a) {
        for (int i = 0; i < w.size(); i++) {
            string b = w[i];
            if (!visited.count(b) && isSimilar(a, b)) {
                visited.insert(b);
                dfs(b);
            }
        }
    }
    
    bool isSimilar(string a, string b) {
        int cnt = 0;
        for (int i = 0; i < a.size(); i++) {
            if (a[i] != b[i]) 
                cnt++;
        }
        return cnt == 2;
    }
};
