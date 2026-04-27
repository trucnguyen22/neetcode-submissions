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
    vector<int> visible;
    vector<int> rightSideView(TreeNode* root) {
        // 1. level order traversal
        // 2. choose the most right at this level
        // 3. generate next level
        queue<TreeNode*> q;
        if (root) q.push(root);

        while (!q.empty()) {
            bool right = false;
            for (int i = q.size(); i > 0; i--) {
                TreeNode *nd = q.front(); 
                q.pop();
                if (!nd) continue;
                if (!right) {
                    visible.push_back(nd->val);
                    right = true;
                }
                q.push(nd->right);
                q.push(nd->left);
            }
        }

        return visible;
    }

    void traversal(TreeNode* curr) {
        visible.push_back(curr->val);
        if (curr->right) traversal(curr->right);
        else if (curr->left) traversal(curr->left);
    }
};
