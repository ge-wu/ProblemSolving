class Solution {
public:
    bool checkPowersOfThree(int n) {
        while (n) {
            int r = n % 3;
            if (r == 2)
                return false;
            n /= 3;
        }
        return true;
    }
};
