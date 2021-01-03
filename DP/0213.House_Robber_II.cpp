class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (!n) return 0;
        if (n == 1) return nums[0];
        
        int doIt = nums[1], dontDoIt = 0;
        int ans1 = 0, ans2 = 0;
        
        for (int i = 2; i < n; i++) {
            int temp1 = doIt, temp2 = dontDoIt;
            doIt = temp2 + nums[i];
            dontDoIt = max(temp1, temp2);
        }
        ans1 = max(doIt, dontDoIt);
        
        doIt = nums[0];
        dontDoIt = 0;
        for (int i = 1; i < n - 1; i++) {
            int temp1 = doIt, temp2 = dontDoIt;
            doIt = temp2 + nums[i];
            dontDoIt = max(temp1, temp2);
        }
        ans2 = max(doIt, dontDoIt);
        return max(ans1, ans2);
    }
};
