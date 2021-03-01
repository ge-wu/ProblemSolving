class Solution {
public:
    int myAtoi(string s) {
        int i = 0, n = s.size();
        long ans = 0;
        bool is_negative = false;
        while (i < n) {
            while (s[i] == ' ') 
                i++;
            if (s[i] == '+' || s[i] == '-' || isdigit(s[i])) {
                is_negative = s[i] == '-' ? true : false;
                if (!isdigit(s[i])) 
                    i++;
                while (i < n && isdigit(s[i])) {
                    ans = ans * 10 + (s[i] - '0');
                    i++;
                    if (ans < INT_MIN || ans > INT_MAX) {
                        return is_negative ? INT_MIN : INT_MAX;
                    }
                } 
                return is_negative ? ans * -1 : ans;
            }
            return 0;
        }
        return 0;
    }
};
