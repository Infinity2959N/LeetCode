/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // LCA is the lowest node T that has both p and q as the descendants
        // A node can be a descendant of itself
        // Approach, if p or q, return, if for a node left and right both return non null, that's the current LCA, else return null
        if(!root || root==p || root==q) return root;
        TreeNode* left= lowestCommonAncestor(root->left, p, q);
        TreeNode* right= lowestCommonAncestor(root->right, p, q);

        if(left && right) return root;
        return (!left)? right: left;
    }
};