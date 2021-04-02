class Solution {
public:
    unordered_map<int, int> parents;
    
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        for (auto & pair: pairs) {
            parents[pair[0]] = pair[0];
            parents[pair[1]] = pair[1];
        }
        
        for (auto & pair: pairs) {
            Union(pair[0], pair[1]);
        }
        
        unordered_map<int, vector<int>> cnt;
        for (auto & it: parents) {
            int temp = Find(it.first);
            cnt[temp].push_back(it.first);
        }
        
        for (auto & it: cnt) {
            vector<int> idx = it.second;
            sort(idx.begin(), idx.end());
            string cur = "";
            for (int k: it.second) {
                cur += s[k];
            }
            sort(cur.begin(), cur.end());
            for (int i = 0; i < idx.size(); i++) {
                s[idx[i]] = cur[i];
            }
        }
        return s;
    }
    
    int Find(int x) {
        if (x != parents[x]) 
            parents[x] = Find(parents[x]);
        return parents[x];
    }
    
    void Union(int x, int y) {
        x = Find(x);
        y = Find(y);
        if (x != y) 
            parents[x] = y;
    }
};
