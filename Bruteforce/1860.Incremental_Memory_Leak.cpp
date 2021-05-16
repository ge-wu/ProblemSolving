class Solution {
public:
    vector<int> memLeak(int A, int B) {
        int i = 1;
        while (A || B) {
            if (A < i && B < i) break;
            if (A >= B) A -= i;
            else B -= i;
            i++;
        }
        return {i, A, B};
    }
};
