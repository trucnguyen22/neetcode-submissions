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
    int goodNodes(TreeNode* root) {
        // 1. premax[&TreeNode] is the max node so far of each node
        // 2. choose if curr > premax[curr]
        // 3. update premax[next]

        unordered_map<TreeNode*, int> premax;
        queue<TreeNode*> q;
        int good = 0;

        if (root) {
            q.push(root);
            premax[root] = root->val;
        }

        while (!q.empty()) {
            TreeNode *curr = q.front();
            q.pop();
            if (premax[curr] <= curr->val) {
                good++;
            }
            if (curr->left) {
                premax[curr->left] = max(premax[curr], curr->val);
                q.push(curr->left);
            }
            if (curr->right) {
                premax[curr->right] = max(premax[curr], curr->val);
                q.push(curr->right);
            }
        }

        return good;
    }
};
