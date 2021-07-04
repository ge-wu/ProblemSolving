class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int curTime = 0, n = dist.size();
        vector<int> times;
        for (int i = 0; i < n; ++i) {
            times.push_back(ceil(1.0 * dist[i] / speed[i]));
        }
        sort(times.begin(), times.end());
        for (int i = 0; i < n; ++i) {
            if (curTime++ >= times[i]) {
                return i;
            }
        }
        return n;
    }
};
