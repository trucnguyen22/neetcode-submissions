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
    bool isBalanced(TreeNode* root) {
        stack<TreeNode*> st;
        unordered_map<TreeNode*, int> height;

        if (root) st.push(root);
        while (!st.empty()) {
            TreeNode* curr = st.top();
            TreeNode *left = curr->left, *right = curr->right;
            if (left && height.find(left) == height.end()) st.push(left);
            else if (right && height.find(right) == height.end()) st.push(right);
            else {
                st.pop();
                int left_h = 0, right_h = 0;
                if (left) left_h = height[left];
                if (right) right_h = height[right];
                if (abs(left_h - right_h) > 1) return false;
                height[curr] = max(left_h, right_h) + 1;
            }
        }

        return true;
    }
};
