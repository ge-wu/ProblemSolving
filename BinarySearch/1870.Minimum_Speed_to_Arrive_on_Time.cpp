class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int left = 1, right = INT_MAX / 2;
        while (left < right) {
            int mid = left + (right - left) / 2;
            double cur = 0.0;
            for (int i = 0; i < dist.size() - 1; i++) {
                cur += ceil(dist[i] * 1.0 / mid);
            }
            cur += (dist.back() * 1.0 / mid);
            if (cur > hour) left = mid + 1;
            else right = mid;
        }
        return left == INT_MAX / 2 ? -1 : left;
    }
};
