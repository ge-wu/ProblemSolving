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
    pair<int, int> ans;
    
    int findBottomLeftValue(TreeNode* root) {
        ans = {root->val, 0};
        dfs(root);
        return ans.first;
    }
    
    void dfs(TreeNode* root, int depth=0) {
        if (!root) return;
        if (depth > ans.second)
            ans = {root->val, depth};
        dfs(root->left, depth + 1);
        dfs(root->right, depth + 1);
    }
};
