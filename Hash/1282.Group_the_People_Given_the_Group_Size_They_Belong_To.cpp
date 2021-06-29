class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& A) {
        unordered_map<int, vector<int>> cnt;
        vector<vector<int>> ans;
        for (int i = 0; i < A.size(); ++i) {
            cnt[A[i]].push_back(i);
        }
        for (auto &it: cnt) {
            int len = it.second.size(), idx = 0;
            for (int i = 0; i < len / it.first; i++) {
                vector<int> cur;
                for (int j = 0; j < it.first; ++j) {
                    cur.push_back(it.second[idx++]);
                }
                ans.push_back(cur);
            }
        }
        return ans;
    }
};
