/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int sumEvenGrandparent(TreeNode* root) {
        return helper(root, NULL, NULL);
    }
    
    int helper(TreeNode *cur, TreeNode *parent, TreeNode *grandParent) {
        if (!cur)
            return 0;
        int ans = 0;
        if (grandParent && grandParent->val % 2 == 0) 
            ans += cur->val;
        ans += helper(cur->left, cur, parent) + helper(cur->right, cur, parent);
        return ans;
    }
};
