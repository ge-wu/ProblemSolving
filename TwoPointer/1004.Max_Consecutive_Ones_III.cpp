class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size(), i, j = 0;
        for (i = 0; i < n; ++i) {
            if (!nums[i]) {
                k--;
            }
            if (k < 0 && !nums[j++]) {
                k++;
            }
        }
        return i - j;
    }
};
