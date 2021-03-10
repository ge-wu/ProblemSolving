class Solution {
public:
    string intToRoman(int num) {
        vector<string> symbol = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        vector<int> values = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        
        string ans = "";
        for (int i = 0; i < values.size(); i++) {
            for (int j = 0; j < num / values[i]; j++) {
                ans += symbol[i];
            }
            num %= values[i];
        }
        return ans;
    }
};
