class Solution {
public:
    vector<int> w;
    vector<int> threeEqualParts(vector<int>& arr) {
        w = arr;
        int cnt = 0, n = w.size();
        for (int i: w) {
            cnt += i;
        }
        if (cnt % 3 != 0) {
            return {-1, -1};
        }
        if (!cnt) {
            return {0, n - 1};
        }
        int k = cnt / 3, idx = 0, temp = 0;
        for (int i = n - 1; i >= 0; --i) {
            temp += w[i];
            if (temp == k) {
                idx = i;
                break;
            }
        }
        int x = helper(0, idx);
        if (x < 0) {
            return {-1, -1};
        }
        int y = helper(x + 1, idx);
        if (y < 0) {
            return {-1, -1};
        }
        return {x, y + 1};
    }
    
    int helper(int left, int right) {
        while (!w[left]) {
            left++;
        }
        while (right < w.size()) {
            if (w[left] != w[right]) {
                return -1;
            }
            left++;
            right++;
        }
        return left - 1;
    }
};
