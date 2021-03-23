struct cmp {
    bool operator() (pair<int, int> &a, pair<int, int> &b) {
        return a.second > b.second;
    }
};

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        vector<int> arr = {1};
        
        for (int p: primes) 
            pq.push(p);
        
        while (true) {
            while (pq.top() == arr.back()) 
                pq.pop();
            long long cur = pq.top();
            for (int p: primes) 
                pq.push(p * cur);
            if (arr.size() == n + 1) 
                break;
            arr.push_back(cur);
            
        }
        return arr[n - 1];
    }
};
