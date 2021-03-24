class Solution {
public:
    int findMaximizedCapital(int k, int W, vector<int>& Profits, vector<int>& Capital) {
        vector<pair<int, int>> projects;
        for (int i = 0; i < Profits.size(); i++) 
            projects.push_back({Capital[i], Profits[i]});
        sort(projects.begin(), projects.end());
        
        priority_queue<int> pq;
        int i = 0;
        while (k) {
            while (i < projects.size() && projects[i].first <= W) {
                pq.push(projects[i].second);
                i++;
            }
            if (!pq.empty()) {
                W += pq.top();
                k--;
                pq.pop();
            } else {
                break;
            }
        }
        return W;
    }
};
