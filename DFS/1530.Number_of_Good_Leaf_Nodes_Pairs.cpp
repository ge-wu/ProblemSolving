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
    vector<int> dfs(int d, TreeNode *root, int &ans) {
        if (!root)
            return {0};
        if (root->left == root->right)
            return {1};
        auto L = dfs(d, root->left, ans);
        auto R = dfs(d, root->right, ans);
        for (int l: L) {
            for (int r: R) {
                if (l && r && l + r <= d)
                    ans++;
            }
        }
        vector<int> temp;
        for (auto l: L) {
            if (l && l + 1 < d) 
                temp.push_back(l + 1);
        }
        for (auto r: R) {
            if (r && r + 1 < d) 
                temp.push_back(r + 1);
        }
        return temp;
    }
    
    int countPairs(TreeNode* root, int distance) {
        int ans = 0;
        dfs(distance, root, ans);
        return ans;
    }
};
