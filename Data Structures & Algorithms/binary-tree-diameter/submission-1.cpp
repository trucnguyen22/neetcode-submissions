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
    int diameter = 0;

    int diameterOfBinaryTree(TreeNode* root) {
        // length is number of edges between any two nodes
        // find longest length

        // intuition 1: level traversal, suppose we know the result of child nodes
        // intuition 2: height

        heightOfNode(root);
        return diameter;
    }

    int heightOfNode(TreeNode* root) {
        if (!root) return 0;

        int left = heightOfNode(root->left);
        int right = heightOfNode(root->right);

        diameter = max(diameter, left + right);

        return max(left, right) + 1;
    }
};
