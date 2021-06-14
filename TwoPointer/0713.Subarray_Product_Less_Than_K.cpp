class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1) {
            return 0;
        }
        long long prod = 1;
        int ans = 0, j = 0;
        for (int i = 0; i < nums.size(); ++i) {
            prod *= nums[i];
            while (prod >= k) {
                prod /= nums[j++];
            }
            ans += (i - j + 1);
        }
        return ans;
    }
};
