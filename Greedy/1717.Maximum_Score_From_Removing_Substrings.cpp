class Solution {
public:
    int maximumGain(string s, int x, int y) {
      if (x < y) {
        reverse(s.begin(), s.end());
        swap(x, y);
      }
      int ans = 0;
      string t;
      
      for (char c: s) {
        t.push_back(c);
        while (t.size() >= 2 && t.substr(t.size() - 2) == "ab") {
          t.pop_back();
          t.pop_back();
          ans += x;
        }
      }
      
      string w;
      for (char c: t) {
        w.push_back(c);
        while (w.size() >= 2 && w.substr(w.size() - 2) == "ba") {
          w.pop_back();
          w.pop_back();
          ans += y;
        }
      }
      return ans;
    }
};
