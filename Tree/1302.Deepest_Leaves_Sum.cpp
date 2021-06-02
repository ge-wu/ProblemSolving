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
    int maxDepth = -1, ans = 0;
    int deepestLeavesSum(TreeNode* root) {
        helper(root, 0);
        return ans;
    }
    
   void helper(TreeNode *root, int depth) {
        if (!root)
            return;
        if (depth > maxDepth) {
            ans = 0;
            maxDepth = depth;
        } 
        if (depth == maxDepth) {
            ans += root->val;
        }
        helper(root->left, depth + 1);
        helper(root->right, depth + 1);
    }
};
