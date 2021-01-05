class Solution {
public:
    int maximumSum(vector<int>& arr) {
      int n = arr.size();
      int with = arr[0], without = arr[0];
      int ans = max(with, without);
      
      for (int i = 1; i < n; i++) {
        int t1 = with, t2 = without;
        with = max(t1 + arr[i], arr[i]);
        without = max(t1, t2 + arr[i]);
        ans = max(ans, max(with, without));
      }
      return ans;
    }
};
