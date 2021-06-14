class Solution {
public:
    class TrieNode {
        public:
        int is_end;
        TrieNode *next[26];
        TrieNode() {
            for (int i = 0; i < 26; i++) {
                next[i] = NULL;
            }
            is_end = false;
        }
    };
    TrieNode *root;
    string ans = "";
    
    string longestWord(vector<string>& words) {
        root = new TrieNode();
        for (string w: words) {
            TrieNode *pointer = root;
            for (char c: w) {
                if (!pointer->next[c - 'a']) {
                    pointer->next[c - 'a'] = new TrieNode();
                }
                pointer = pointer->next[c - 'a'];
            }
            pointer->is_end = true;
        }
        dfs("", root);
        return ans;
    }
    
    void dfs(string cur, TrieNode *node) {
        if (!root) {
            return;
        }
        if (cur.size() >= ans.size()) {
            if (cur.size() == ans.size()) {
                ans = min(cur, ans);
            } else {
                ans = cur;
            }
        }
        for (char c = 'a'; c <= 'z'; ++c) {
            if (node->next[c - 'a'] && node->next[c - 'a']->is_end) {
                cur += c;
                dfs(cur, node->next[c - 'a']);
                cur.pop_back();
            }
        }
    }
};
