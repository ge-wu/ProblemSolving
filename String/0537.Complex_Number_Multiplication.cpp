class Solution {
public:
    pair<int, int> parseComplexEqu (string str) {
        str.pop_back();
        int idx = str.find("+");
        int a = stoi(str.substr(0, idx));
        int b = stoi(str.substr(idx + 1));
        return {a, b};
    }
    
    string complexNumberMultiply(string s1, string s2) {
        pair<int, int> p = parseComplexEqu(s1);
        pair<int, int> q = parseComplexEqu(s2);
        
        int a = p.first, b = p.second, c = q.first, d = q.second;
        return to_string(a * c - b * d) + "+" + to_string(a * d + b * c) + "i";
    }
};
