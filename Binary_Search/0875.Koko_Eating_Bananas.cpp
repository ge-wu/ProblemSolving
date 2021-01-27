class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int H) {
        int left = 1, right = 1000000000;
        while (left < right) {
            int mid = left + (right - left) / 2;
            int time = 0;
            for (int p: piles) {
                time += ceil((float) p / mid);
            }
            if (time <= H) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};
