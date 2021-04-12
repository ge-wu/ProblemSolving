class Solution {
public:
    int minSideJumps(vector<int>& obstacles) {
        int a = 1, b = 0, c = 1;
        for (int obs: obstacles) {
            if (obs == 1) a = INT_MAX / 2;
            if (obs == 2) b = INT_MAX / 2;
            if (obs == 3) c = INT_MAX / 2;
            
            if (obs != 1) a = min(a, min(b + 1, c + 1));
            if (obs != 2) b = min(b, min(a + 1, c + 1));
            if (obs != 3) c = min(c, min(a + 1, b + 1));
        }
        return min(a, min(b, c));
    }
};
