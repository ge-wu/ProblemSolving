class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> Map;
        for (string str: strs) {
            string temp = str;
            sort(str.begin(), str.end());
            Map[str].push_back(temp);
        }
        vector<vector<string>> ans;
        for (auto &it: Map) {
            ans.push_back(it.second);
        }
        return ans;
    }
};
