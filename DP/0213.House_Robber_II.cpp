class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        }
        int ans1, ans2;
        int rob, noRob;
        
        rob = nums[0];
        noRob = 0;
        for (int i = 1; i < nums.size() - 1; i++) {
            int a = rob, b = noRob;
            rob = nums[i] + b;
            noRob = max(a, b);
        }
        ans1 = max(rob, noRob);
        
        rob = nums[1];
        noRob = 0;
        for (int i = 2; i < nums.size(); i++) {
            int a = rob, b = noRob;
            rob = nums[i] + b;
            noRob = max(a, b);
        }
        return max(ans1, max(rob, noRob));
    }
};
