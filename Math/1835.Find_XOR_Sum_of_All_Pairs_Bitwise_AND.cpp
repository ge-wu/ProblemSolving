class Solution {
public:
    int getXORSum(vector<int>& arr1, vector<int>& arr2) {
        int x = 0;
        for (int n: arr2) {
            x ^= n;
        }
        int ans = 0;
        for (int n: arr1) {
            ans ^= (n & x);
        }
        return ans;
    }
};
