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
        int diff=0;
        height(root, diff);

        return diff<=1;
    }
private:
    int height(TreeNode* root, int& diff){
        if(!root)   return 0;

        int left=height(root->left, diff);
        int right=height(root->right, diff);

        diff=max(diff, abs(left-right));
        //If for any node the diff will be greater than 1, it will be stored
        return max(left, right)+1;
    }
};