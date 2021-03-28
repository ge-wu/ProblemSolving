class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        vector<int> ans;
        
        int leftIdx = -1, rightIdx = -1;
        
        while (left <= right) {
            int mid = (left + right) / 2;
            if (target > nums[mid]) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        leftIdx = left;
        
        left = 0;
        right = nums.size() - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (target >= nums[mid]) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        rightIdx = right;
        if (leftIdx <= rightIdx) {
            return {leftIdx, rightIdx};
        }
        return {-1, -1};        
    }
};
