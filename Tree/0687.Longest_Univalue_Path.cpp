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
    int ans = 0;
    int longestUnivaluePath(TreeNode* root) {
        int foo = helper(root);
        return ans;
    }
    
    int helper(TreeNode *root) {
        if (!root) 
            return 0;
        int l = helper(root->left);
        int r = helper(root->right);
        int x = 0, y = 0;
        if (root->left && root->left->val == root->val) 
            x = l + 1;
        if (root->right && root->right->val == root->val)
            y = r + 1;
        ans = max(ans, x + y);
        return max(x, y);
    }
};
