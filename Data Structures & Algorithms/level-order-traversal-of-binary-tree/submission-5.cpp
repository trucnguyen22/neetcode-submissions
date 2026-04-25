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
    vector<vector<int>> levelOrder(TreeNode* root) {
        // 1. make sure only push nodes at this level
        // 2. push next level's nodes after print out current level
        vector<vector<int>> levels;
        queue<TreeNode*> q;
        if (root) q.push(root);

        while (true) {
            vector<TreeNode*> next;
            vector<int> vals;
            while (!q.empty()) {
                TreeNode* curr = q.front();
                q.pop();
                if (!curr) continue;
                vals.push_back(curr->val);
                next.push_back(curr->left);
                next.push_back(curr->right);
            }
            if (vals.size()) {
                levels.push_back(vals);
                for (auto nd : next) q.push(nd);
            } else {
                return levels;
            }
        }

        return levels;
    }
};
