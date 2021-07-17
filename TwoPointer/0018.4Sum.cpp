class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        if (nums.size() < 4) {
            return ans;
        }
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            if (nums[i] * 4 > target) {
                break;
            }
            if (nums[i] + nums.back() * 3 < target) {
                continue;
            }
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            for (int j = i + 1; j < n; ++j) {
                if (nums[i] + nums[j] * 3 > target) {
                    break;
                }
                if (nums[i] + nums[j] + nums.back() * 2 < target) {
                    continue;
                }
                if (j > i + 1 && nums[j] == nums[j - 1]) {
                    continue;
                }
                int l = j + 1, r = n - 1;
                while (l < r) {
                    int temp = nums[i] + nums[j] + nums[l] + nums[r];
                    if (temp == target) {
                        ans.push_back({nums[i], nums[j], nums[l], nums[r]});
                        l++;
                        r--;
                        while (l < n && nums[l] == nums[l - 1]) {
                            l++;
                        }
                        while (r >= 0 && nums[r] == nums[r + 1]) {
                            r--;
                        }
                    } else if (temp > target) {
                        r--;
                    } else {
                        l++;
                    }
                }
            }
        }
        return ans;
    }
};
