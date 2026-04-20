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

        // 1. post-order traversal
        // 2. compute and maintain height for each node
        
        unordered_map<TreeNode*, int> height;
        stack<TreeNode*> st;
        int diameter = 0;

        if (root) st.push(root);
        while (!st.empty()) {
            TreeNode* curr = st.top();
            
            if (curr->left && height.find(curr->left) == height.end()) 
                st.push(curr->left);
            else if (curr->right && height.find(curr->right) == height.end()) 
                st.push(curr->right);
            else {
                int left = 0, right = 0;
                st.pop();
                if (curr->left) left = height[curr->left];
                if (curr->right) right = height[curr->right];
                height[curr] = max(left, right) + 1;
                diameter = max(diameter, left + right);
            }
        }

        return diameter;
    }
};
