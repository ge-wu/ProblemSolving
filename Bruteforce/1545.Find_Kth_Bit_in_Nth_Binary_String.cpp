class Solution {
public:
    char findKthBit(int n, int k) {
        return helper(n)[k - 1];
    }
    
    string helper(int i) {
        if (i == 1) return "0";
        string cur = helper(i - 1), temp = "";
        for (int i = cur.size() - 1; i >= 0; i--) {
            temp += to_string(cur[i] - '0' ^ 1);
        }
        return cur + "1" + temp;
    }
};
