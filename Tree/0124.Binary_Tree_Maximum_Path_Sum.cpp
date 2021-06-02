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
    int ans = INT_MIN;
    int maxPathSum(TreeNode* root) {
        return max(ans, helper(root));
    }
    
    int helper(TreeNode *root) {
        if (!root)
            return INT_MIN;
        int l = max(0, helper(root->left));
        int r = max(0, helper(root->right));
        ans = max(ans, root->val + l + r);
        return root->val + max(l, r);
    }
};
