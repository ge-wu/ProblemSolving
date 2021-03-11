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
    int ans = 0, max_level = 0;
    int deepestLeavesSum(TreeNode* root) {
        dfs(root, 0);
        return ans;
    }
    
    void dfs(TreeNode *root, int level) {
        if (!root) return;
        if (level > max_level) {
            ans = 0;
            max_level = level;
        }
        
        if (level == max_level) ans += root->val;
        dfs(root->left, level + 1);
        dfs(root->right, level + 1);
    }
};
