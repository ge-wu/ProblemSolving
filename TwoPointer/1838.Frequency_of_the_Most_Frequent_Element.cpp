class Solution {
public:
    int maxFrequency(vector<int>& nums, long k) {
        sort(nums.begin(), nums.end());
        int i = 0, j;
        for (j = 0; j < nums.size(); j++) {
            k += nums[j];
            if (k < (long) nums[j] * (j - i + 1)) {
                k -= nums[i];
                i++;
            }
        }
        return j - i;
    }
};
