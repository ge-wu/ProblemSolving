class Solution {
public:
    int rob(vector<int>& nums) {
        if (!nums.size()) {
            return 0;
        }
        
        int doIt = nums[0], dontDoIt = 0;
        for (int i = 1; i < nums.size(); i++) {
            int a = doIt, b = dontDoIt;
            doIt = b + nums[i];
            dontDoIt = max(a, b);
        }
        return max(doIt, dontDoIt);
    }
};
