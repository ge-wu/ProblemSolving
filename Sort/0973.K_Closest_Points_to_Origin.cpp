class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& A, int k) {
        sort(A.begin(), A.end(), [] (const vector<int> &x, const vector<int> &y) {
            return sqrt(pow(x[0], 2) + pow(x[1], 2)) < sqrt(pow(y[0], 2) + pow(y[1], 2));
        });
        return {A.begin(), A.begin() + k};
    }
};
