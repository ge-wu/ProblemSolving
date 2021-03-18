class Solution {
public:
    Solution(double radius, double x_center, double y_center) {
        radius_ = radius;
        x_ = x_center;
        y_ = y_center;
    }
    
    vector<double> randPoint() {
        double r = radius_ * sqrt((double) rand() / RAND_MAX);
        double theta = (double) rand() / RAND_MAX * 2 * 3.1415926;
        // cout << x_ + r * cos(theta);
        return{x_ + r * cos(theta), y_ + r * sin(theta)};
    }
    
private:
    double radius_, x_, y_;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */
