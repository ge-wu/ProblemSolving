class MapSum {
public:
    class TrieNode {
        public:
            int isEnd;
            TrieNode *next[26];
            TrieNode() {
                for (int i = 0; i < 26; i++) {
                    next[i] = NULL;
                }
                isEnd = 0;
            }
    };
    TrieNode *root;
    int ans;
    /** Initialize your data structure here. */
    MapSum() {
        root = new TrieNode();
    }
    
    void insert(string key, int val) {
        TrieNode *pointer = root;
        for (char c: key) {
            int temp = c - 'a';
            if (!pointer->next[temp]) 
                pointer->next[temp] = new TrieNode();
            pointer = pointer->next[temp];
        }
        pointer->isEnd = val;
    }
    
    int sum(string prefix) {
        TrieNode *pointer = root;
        ans = 0;
        for (char c: prefix) {
            TrieNode *temp = pointer->next[c - 'a'];
            if (temp)
                pointer = temp;
            else
                return 0;
        }
        helper(pointer);
        return ans;
    }
    
    void helper(TrieNode *root) {
        if (!root) 
            return;
        if (root->isEnd)  
            ans += root->isEnd;
        for (int k = 0; k < 26; k++) {
            helper(root->next[k]);
        }
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */
