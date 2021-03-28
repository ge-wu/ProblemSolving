class Solution {
public:
    /* this is a math problem because the interesting fact about English numbers */
    string originalDigits(string s) {
        vector<int> cnt(26, 0);
        vector<string> letters = {
            "zero", "two", "four", "six", "eight",
            "one", "three", "five", "seven", "nine"
        };
        vector<int> nums = {0, 2, 4, 6, 8, 1, 3, 5, 7, 9};

        for (char c: s) cnt[c - 'a']++;
        
        string ans = "";
        for (int i = 0; i < 10; i++) {
            int temp = INT_MAX;
            for (int j = 0; j < letters[i].size(); j++) 
                temp = min(temp, cnt[letters[i][j] - 'a']);
            for (int j = 0; j < temp; j++)
                ans.push_back(nums[i] + '0');
            for (int j = 0; j < letters[i].size(); j++)
                cnt[letters[i][j] - 'a'] -= temp;
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};
