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
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int level = 0;
        while (!q.empty()) {
            int n = q.size();
            vector<int> curLevel;
            while (n--) {
                TreeNode *node = q.front(); 
                q.pop();
                if ((node->val & 1) == (level & 1)) 
                    return false;
                curLevel.push_back(node->val);
                if (node->left) 
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
            if (level & 1) {
                reverse(curLevel.begin(), curLevel.end());
            }
            for (int i = 1; i < curLevel.size(); i++) {
                if (curLevel[i-1] >= curLevel[i])
                    return false;
            }
            level++;
        }
        return true;
    }
};
