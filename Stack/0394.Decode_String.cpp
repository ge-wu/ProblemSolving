class Solution {
public:
    string decodeString(string s) {
        stack<string> letters;
        stack<int> nums;
        
        int i = 0, n = s.size();
        string str = "";
        while (i < n) {
            if (isdigit(s[i])) {
                int num = s[i] - '0';
                while (i + 1 < n && isdigit(s[i + 1])) {
                    num = num * 10 + (s[i + 1] - '0');
                    i++;
                }
                nums.push(num);
            } else if (s[i] == '[') {
                letters.push(str);
                str = "";
            } else if (s[i] == ']') {
                int a = nums.top(); nums.pop();
                string b = letters.top(); letters.pop();
                string temp = "";
                while (a--) temp += str;
                str = b + temp;
            } else {
                str.push_back(s[i]);
            }
            i++;
        }
        return str;
    }
};
