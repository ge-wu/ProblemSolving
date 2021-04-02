class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n = nums.size();
        if (!n) {
            return 0;
        }
        map<int, int> cnt;
        for (int num: nums) {
            cnt[num]++;
        }
        
        vector<pair<int, int>> temp;
        for (auto it: cnt) {
            temp.push_back(it);
        }
        
        int del = temp[0].first * temp[0].second, dontDel = 0;
        
        for (int i = 1; i < temp.size(); i++) {
            int a = del, b = dontDel;
            if (temp[i].first != temp[i - 1].first + 1) {
                del = max(a, b) + temp[i].first * temp[i].second;
            } else {
                del = b + temp[i].first * temp[i].second;
            }
            dontDel = max(a, b);
        }
        return max(del, dontDel);
    }
};
