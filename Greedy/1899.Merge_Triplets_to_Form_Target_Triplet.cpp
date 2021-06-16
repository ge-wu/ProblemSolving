class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        vector<int> cnt = {0, 0, 0};
        for (auto &x: triplets) {
            if (x[0] <= target[0] && x[1] <= target[1] && x[2] <= target[2]) {
                cnt[0] = max(cnt[0], x[0]);
                cnt[1] = max(cnt[1], x[1]);
                cnt[2] = max(cnt[2], x[2]);
            }
        }
        return cnt == target;
    }
};
