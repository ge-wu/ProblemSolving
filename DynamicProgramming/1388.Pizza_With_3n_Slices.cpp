class Solution {
public:
    int maxSizeSlices(vector<int>& slices) {
        int n = slices.size();
        return max(helper(0, n - 2, slices), helper(1, n - 1, slices));
    }
    
    int helper(int start, int end, vector<int>& slices) {
        int k = slices.size() / 3;
        vector<int> a(k + 1, 0); 
        vector<int> b(k + 1, 0);
        
        for (int i = start; i <= end; i++) {
            for (int j = min(k, i - start + 1); j >= 1; j--) {
                b[j] = max(b[j], a[j]);      
                a[j] = b[j-1] + slices[i];   
            }
        }
        return max(a[k], b[k]);        
    }
};
