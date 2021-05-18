class Solution {
public:
    string numberToWords(int num) {
        if (!num) return "Zero";

        vector<string> largeNames = {"", "Thousand ", "Million ", "Billion "};
        string ans = "";
        for (int i = 0; i < largeNames.size() && num; i++, num/=1000) {
            if (!(num % 1000)) continue;
            ans = helper(num % 1000) + largeNames[i] + ans;
        }
        if (ans.back() == ' ') 
            ans.pop_back();
        return ans;
    }

    string helper(int num) {
        vector<string> smallNames = {
            "", "One ", "Two ", "Three ", "Four ", "Five ", "Six ", "Seven ", 
            "Eight ", "Nine ", "Ten ", "Eleven ", "Twelve ", "Thirteen ", 
            "Fourteen ", "Fifteen ", "Sixteen ", "Seventeen ", "Eighteen ", 
            "Nineteen "
        };
        vector<string> cardinalNames = {
            "", "", "Twenty ", "Thirty ", "Forty ", "Fifty ", "Sixty ", 
            "Seventy ", "Eighty ", "Ninety "
        };
        string ans = "";
        if (num % 100) {
            if (num % 100 < 20) ans += smallNames[num % 100];
            else ans += cardinalNames[num % 100 / 10] + smallNames[num % 10];
        }
        if (num >= 100) {
            ans = smallNames[num / 100] + "Hundred " + ans;
        }
        return ans;
    }
};
