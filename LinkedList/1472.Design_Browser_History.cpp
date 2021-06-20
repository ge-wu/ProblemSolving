class BrowserHistory {
public:
    class Node {
        public:
        string val;
        Node *next, *prev;
        Node(string s) {
            val = s;
            next = prev = NULL;
        }
    };
    Node *pointer;
    
    BrowserHistory(string homepage) {
        pointer = new Node(homepage);
    }
    
    void visit(string url) {
        Node *new_page = new Node(url);
        new_page->prev = pointer;
        pointer->next = new_page;
        pointer = new_page;
    }
    
    string back(int steps) {
        while (pointer->prev && steps) {
            pointer = pointer->prev;
            --steps;
        }
        return pointer->val;
    }
    
    string forward(int steps) {
        while (pointer->next && steps) {
            pointer = pointer->next;
            --steps;
        }
        return pointer->val;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
