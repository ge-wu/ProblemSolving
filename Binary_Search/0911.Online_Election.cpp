class TopVotedCandidate {
public:
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        times_ = times;
        
        map<int, int> cnt;
        int cur_lead = -1;
        
        for (int i = 0; i < persons.size(); i++) {
            cnt[persons[i]]++;
            if (cnt[persons[i]] >= cnt[cur_lead]) {
                cur_lead = persons[i];
            }
            lead_.push_back(cur_lead);
        }
    }

    int q(int t) {
        int left = 0, right = lead_.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int mid_val = times_[mid];
            if (mid_val == t) {
                return lead_[mid];
            } else if (mid_val > t) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return lead_[left - 1];
    }
private:
    vector<int> lead_, times_;
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */
