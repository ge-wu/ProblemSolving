class Solution {
    class TrieNode {
        public:
            TrieNode *next[2];
    };
    
public:
    int findMaximumXOR(vector<int>& nums) {
        TrieNode *trie = new TrieNode();
        
        for (int num: nums) {
            TrieNode *pointer = trie;
            for (int i = 31; i >= 0; --i) {
                int temp = (num >> i) & 1;
                if (!pointer->next[temp])
                    pointer->next[temp] = new TrieNode();
                pointer = pointer->next[temp];
            }
        }
        
        int ans = INT_MIN;
        for (int num: nums) {
            int cur = 0;
            TrieNode *pointer = trie;
            for (int i = 31; i >= 0; --i) {
                int temp = (num >> i) & 1;
                cur *= 2;
                if (pointer->next[1 - temp]) {
                    cur++;
                    pointer = pointer->next[1 - temp];
                } else {
                    pointer = pointer->next[temp];
                }
            }
            ans = max(ans, cur);
        }
        return ans;
    }
};
