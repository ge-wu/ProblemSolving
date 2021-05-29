class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> w;
        for (int num: nums) 
            w.push_back(to_string(num));
        sort(w.begin(), w.end(), [] (string &x, string &y){return x + y > y + x;});
        string ans = "";
        for (string t: w) 
            ans += t;
        while (ans.size() > 1 && ans[0] == '0')
            ans.erase(0, 1);
        return ans;
    }
};
