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
    int diameter=0;
public:
    int diameterOfBinaryTree(TreeNode* root) {
        diameterOfBT(root);
        return diameter;
    }
private:
    int diameterOfBT(TreeNode* root){
        // height of left subtree+ height of right subtree
        if(!root) return 0;
        int left= diameterOfBT(root->left);
        int right= diameterOfBT(root->right);
        diameter= max(diameter,left+right); // number of edges, not number of nodes
        return 1+ max(left, right);
    }
};