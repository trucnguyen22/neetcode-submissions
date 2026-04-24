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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) return root;

        int curr_val = root->val;
        if (p->val <= curr_val) {
            if (curr_val == p->val || curr_val <= q->val) return root;
            return lowestCommonAncestor(root->left, p, q);
        } else {
            if (q->val <= curr_val) return root;
            return lowestCommonAncestor(root->right, p, q);
        }

        return nullptr;
    }
};
