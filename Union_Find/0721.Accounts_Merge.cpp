class Solution {
public:
    unordered_map<string, string> parents;
    
    vector<vector<string>> accountsMerge(vector<vector<string>>& acc) {
        unordered_map<string, string> owners;
        unordered_map<string, set<string>> comb;
        
        for (int i = 0; i < acc.size(); i++) {
            for (int j = 1; j < acc[i].size(); j++) {
                parents[acc[i][j]] = acc[i][j];
                owners[acc[i][j]] = acc[i][0];
            }
        }
        for (int i = 0; i < acc.size(); i++) {
            for (int j = 2; j < acc[i].size(); j++) {
                Union(acc[i][j], acc[i][j - 1]);
            }
        }
        for (int i = 0; i < acc.size(); i++) {
            for (int j = 1; j < acc[i].size(); j++) {
                parents[acc[i][j]] = Find(acc[i][j]);
                comb[parents[acc[i][j]]].insert(acc[i][j]);
            }
        }
        vector<vector<string>> ans;
        for (auto &it: comb) {
            vector<string> temp;
            temp.push_back(owners[it.first]);
            for (auto &x: it.second) {
                temp.push_back(x);
            }
            ans.push_back(temp);
        }
        
        return ans;
    }
    
    void Union(string x, string y) {
        x = Find(x);
        y = Find(y);
        if (x != y) {
            parents[x] = y;
        }
    }
    
    string Find(string x) {
        if (x != parents[x]) {
            parents[x] = Find(parents[x]);
        }
        return parents[x];
    }
};
