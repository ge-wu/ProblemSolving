class Solution {
public:
    int numberOfRounds(string A, string B) {
        int h1, m1, h2, m2;
        sscanf(A.c_str(), "%d:%d", &h1, &m1);
        sscanf(B.c_str(), "%d:%d", &h2, &m2);
        if (m1 % 15 != 0) {
            m1 = m1 + 15 - (m1 % 15);
        }
        int m = m2 - m1;
        if (m < 0) {
            --h2;
            m += 60;
        }
        return ((h2 - h1 + 24) % 24 * 60 + m) / 15;
    }
};

