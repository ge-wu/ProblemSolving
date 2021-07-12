class MedianFinder {
public:
    /** initialize your data structure here. */
    multiset<int> l, r;
    MedianFinder() {
        l.clear();
        r.clear();
    }
    
    void addNum(int num) {
        if (l.empty() || num < *(--l.end())) {
            l.insert(num);
        } else {
            r.insert(num);
        } 
        if (r.size() > l.size()) {
            l.insert(*r.begin());
            r.erase(r.begin());
        } else if (l.size() - r.size() >= 2) {
            r.insert(*(--l.end()));
            l.erase(--l.end());

        }
    }
    
    double findMedian() {
        int m = l.size(), n = r.size();
        if ((m + n) & 1) {
            return (double) *(--l.end());
        }
        return (*(--l.end()) + *r.begin()) / 2.0;
    }
};


/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
