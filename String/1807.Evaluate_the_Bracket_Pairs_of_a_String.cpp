class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> Map;
        for (auto &it: knowledge) Map[it[0]] = it[1];
        
        string ans = "";
        for (int i = 0; i < s.size(); i++) {
            int j = i;
            string temp = "";
            while (s[i] == '(' && j + 1 < s.size() && s[j + 1] != ')') {
                temp += s[++j];
            }
            if (j == i) {
                ans += s[j];
            } else {
                ans += (Map.find(temp) != Map.end()) ? Map[temp] : "?";
                i = j + 1;
            }
        }
        return ans;
    }
};
