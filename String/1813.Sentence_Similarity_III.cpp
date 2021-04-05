class Solution {
public:
    bool areSentencesSimilar(string sent1, string sent2) {
        if (sent1 == sent2) return true;
        istringstream ss1(sent1);
        istringstream ss2(sent2);
        
        deque<string> dq1, dq2;
        for (string s; ss1 >> s;) dq1.push_back(s);
        for (string s; ss2 >> s;) dq2.push_back(s);
        
        while (dq1.size() && dq2.size() && dq1.front() == dq2.front()) {
            dq1.pop_front();
            dq2.pop_front();
        }
        while (dq1.size() && dq2.size() && dq1.back() == dq2.back()) {
            dq1.pop_back();
            dq2.pop_back();
        }
        return !dq1.size() || !dq2.size();
    }
};
