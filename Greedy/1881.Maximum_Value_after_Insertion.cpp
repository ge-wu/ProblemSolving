class Solution {
public:
    string maxValue(string n, int x) {
        int i = 0;
        if (n[0] != '-') {
            while (i < n.size() && n[i] - '0' >= x) {
                i++;
            }
        } else {
            while (i < n.size() && n[i] - '0' <= x) {
                i++;
            }
        }
        n.insert(i, to_string(x));
        return n;
    }
};
