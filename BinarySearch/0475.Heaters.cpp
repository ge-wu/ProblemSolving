class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(heaters.begin(), heaters.end());
        int ans = 0, r;
        for (int h: houses) {
            auto pos = lower_bound(heaters.begin(), heaters.end(), h);
            if (pos == heaters.begin()) {
                r = heaters[0] - h;
            } else if (pos == heaters.end()) {
                r = h - heaters.back();
            } else {
                r = min(*pos - h, h - *(pos - 1));
            }
            ans = max(ans, r);
        }
        return ans;
    }
};
