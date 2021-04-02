class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp = {1};
        int a = 0, b = 0, c = 0;
        int x, y, z;
        
        for (int i = 0; i < n - 1; i++) {
            x = dp[a] * 2;
            y = dp[b] * 3;
            z = dp[c] * 5;
            
            int temp = min(x, min(y, z));
            if (temp == x) 
                a++;
            if (temp == y)
                b++;
            if (temp == z)
                c++;
            dp.push_back(temp);
        }
        return dp[n - 1];
    }
};
