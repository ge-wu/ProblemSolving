class Solution {
public:
    string optimalDivision(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) 
            return to_string(nums[0]);
        if (n == 2) 
            return to_string(nums[0]) + "/" + to_string(nums[1]);
        string temp = "(";
        for (int i = 1; i < n; i++) {
            temp += to_string(nums[i]);
            temp += (i != n - 1) ? "/" : ")";
        }
        return to_string(nums[0]) + "/" + temp;
    }
};
