class Solution {
public:
    string arrangeWords(string text) {
        int i = 0, n = text.size();
        map<int, vector<string>> arr;
        while (i < n) {
            string cur = "";
            while (i < n && text[i] != ' ') 
                cur += text[i++];
            if (cur[0] >= 'A' && cur[0] <= 'Z')
                cur[0] = tolower(cur[0]);
            arr[cur.size()].push_back(cur);
            i++;
        }
        string ans = "";
        for (auto &it: arr) {
            for (string x: it.second) {
                ans += x + " ";
            }
        }
        ans[0] = toupper(ans[0]);
        ans.pop_back();
        return ans;
    }
};
