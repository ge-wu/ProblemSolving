class Solution {
public:
    vector<int> getStrongest(vector<int>& arr, int k) {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        int m = arr[(n - 1) / 2];
        sort(arr.begin(), arr.end(), [&] (const int a, const int b) {
            if (abs(a - m) == abs(b - m)) {
                return a > b;
            } else {
                return abs(a - m) > abs(b - m);
            }
        });
        return {arr.begin(), arr.begin() + k};
    }
};
