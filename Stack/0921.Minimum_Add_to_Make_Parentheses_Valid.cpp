class Solution {
public:
    int minAddToMakeValid(string S) {
        stack<char> s;
        for (char c: S) {
            if (!s.empty() && c == ')' && s.top() == '(')
                s.pop();
            else
                s.push(c);
        }
        return s.size();
    }
};
