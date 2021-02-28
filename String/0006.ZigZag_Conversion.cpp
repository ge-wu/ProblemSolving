class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) 
            return s;
        
        int n = (numRows - 1) + (numRows - 1), m = s.size();
        string ans = "";
        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j + i < m; j += n) {
                ans += s[i + j];
                if (i != 0 && i != numRows - 1 && j + n - i < m) 
                    ans += s[j + n - i];
            }
        }
        return ans;
    }
};
