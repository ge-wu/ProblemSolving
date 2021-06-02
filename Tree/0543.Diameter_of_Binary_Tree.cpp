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
    int diameterOfBinaryTree(TreeNode* root) {
        int foo = helper(root);
        return ans;
    }
    
    int helper(TreeNode *root) {
        if (!root)
            return -1;
        int l = helper(root->left) + 1;
        int r = helper(root->right) + 1;
        ans = max(ans, l + r);
        return max(l, r);
    }
};
