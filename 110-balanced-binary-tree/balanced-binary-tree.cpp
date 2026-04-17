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
        // Approach: For each node, find the height of left and right subtree, if the absolute difference is more than 1, it's not a balanced BST
        return findBalanced(root)>=0? true: false;
    }
private:
    int findBalanced(TreeNode* node){
        if(!node) return 0;
        int left= findBalanced(node->left);
        int right= findBalanced(node->right);

        return (left==-1 || right==-1 || abs(left-right)>1)? -1: max(left,right)+1;
    }
};