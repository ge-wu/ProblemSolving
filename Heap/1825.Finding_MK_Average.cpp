class MKAverage {
public:
    int m, k;
    
    struct query {
        multiset<int> s;
        long long sum = 0;
        void insert(int x) {
            s.insert(x);
            sum += x;
        }
        void remove(int x) {
            s.erase(s.find(x));
            sum -= x;
        }
    } left, right, mid;
    
    vector<int> q;
        
    MKAverage(int m, int k): m(m), k(k) {}
    
    void addElement(int num) {
        q.push_back(num);
        if (q.size() < m) return;
        if (q.size() == m) {
            auto w = q;
            sort(w.begin(), w.end());
            for (int i = 0; i < k; i++) left.insert(w[i]);
            for (int i = k; i < m - k; i++) mid.insert(w[i]);
            for (int i = m - k; i < m; i++) right.insert(w[i]);
        } else {
            mid.insert(num);
            if (*left.s.rbegin() > *mid.s.begin()) {
                int x = *mid.s.begin(), y = *left.s.rbegin();
                mid.remove(x), left.insert(x);
                left.remove(y), mid.insert(y);
            }
            if (*mid.s.rbegin() > *right.s.begin()) {
                int x = *mid.s.rbegin(), y = *right.s.begin();
                mid.remove(x), right.insert(x);
                right.remove(y), mid.insert(y);
            }
            
            num = q[q.size() - m - 1];
            if (mid.s.count(num)) mid.remove(num);
            else if (left.s.count(num)) {
                left.remove(num);
                int x = *mid.s.begin();
                mid.remove(x), left.insert(x);
            } else {
                right.remove(num);
                int x = *mid.s.rbegin();
                mid.remove(x), right.insert(x);
            }
        }
    }
    
    int calculateMKAverage() {
        if (q.size() < m) return -1;
        return mid.sum / mid.s.size();
    }
};

/**
 * Your MKAverage object will be instantiated and called as such:
 * MKAverage* obj = new MKAverage(m, k);
 * obj->addElement(num);
 * int param_2 = obj->calculateMKAverage();
 */
