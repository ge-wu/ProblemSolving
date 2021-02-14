class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int left = 1, right = 1e9;
        while (left < right) {
            int mid = left + (right - left) / 2;
            int cnt = 0;
            for (int num: nums) {
                cnt += (num - 1) / mid;
            }
            if (cnt > maxOperations) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }
};
