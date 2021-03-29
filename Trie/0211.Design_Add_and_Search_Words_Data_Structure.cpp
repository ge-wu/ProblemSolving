class WordDictionary {
public:
    class TrieNode {
        public: 
            bool isEnd;
            TrieNode *next[26];
        
            TrieNode() {
                for (int i = 0; i < 26; i++) {
                    next[i] = NULL;
                }
                isEnd = false;
            }
    };
    
    TrieNode *root;
    
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new TrieNode;
    }
    
    void addWord(string word) {
        TrieNode *pointer = root;
        for (int i = 0; i < word.size(); i++) {
            int temp = word[i] - 'a';
            if (!pointer->next[temp]) {
                pointer->next[temp] = new TrieNode();
            }
            pointer = pointer->next[temp];
        }
        pointer->isEnd = true;
    }
    
    bool search(string word) {
        TrieNode *pointer = root;
        return dfs(pointer, word, 0);
    }
    
    bool dfs(TrieNode *root, string word, int i) {
        if (!root) 
            return false;
        if (i == word.size()) 
            return root->isEnd;
        
        if (word[i] != '.') {
            return dfs(root->next[word[i] - 'a'], word, i + 1);
        } else {
            bool temp = false;
            for (int k = 0; k < 26; k++) {
                if (dfs(root->next[k], word, i + 1)) {
                    temp = true;
                    break;
                }
            }
            return temp;
        }
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
