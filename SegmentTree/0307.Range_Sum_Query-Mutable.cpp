class NumArray {
    class SegTreeNode {
        public:
        SegTreeNode *left;
        SegTreeNode *right;
        int start, end;
        int val;
        
        SegTreeNode(int a, int b) {
            start = a;
            end = b;
            val = 0;
            left = NULL;
            right = NULL;
        }
    };
    
public:
    SegTreeNode *root;
    vector<int> nums;
    
    NumArray(vector<int>& nums) {
        this->nums = nums;
        int n = nums.size();
        root = new SegTreeNode(0, n - 1);
        init(root, 0, n - 1);
    }
    
    void update(int index, int val) {
        updateNode(root, index, val);
    }
    
    int sumRange(int left, int right) {
        return search(root, left, right);
    }
    
            
    void init(SegTreeNode *node, int a, int b) {
        int mid = a + (b - a) / 2;
        if (a == b) {
            node->val = nums[a];
            return;
        }
        if (node->left == NULL) {
            node->left = new SegTreeNode(a, mid);
            node->right = new SegTreeNode(mid + 1, b);
        }
        init(node->left, a, mid);
        init(node->right, mid + 1, b);
        node->val = node->left->val + node->right->val;
    }

    void updateNode(SegTreeNode *node, int idx, int val) {
        int l = node->start, r = node->end;
        if (idx < l || idx > r) 
            return;
        if (l == r) {
            node->val = val;
            return;
        }
        updateNode(node->left, idx, val);
        updateNode(node->right, idx, val);
        node->val = node->left->val + node->right->val;
    }

    int search(SegTreeNode *node, int a, int b) {
        int l = node->start, r = node->end;
        if (b < l || a > r) 
            return 0;
        if (a <= l && r <= b) 
            return node->val;
        return search(node->left, a, b) + search(node->right, a, b);
        
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
