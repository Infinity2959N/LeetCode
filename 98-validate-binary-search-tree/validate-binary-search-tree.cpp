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
    bool isValidBST(TreeNode* root) {
        // Hint for an elegant approach: A tree is a valid BST if and only if its Inorder Traversal results in a strictly increasing sorted array.
        return isValid(root, LLONG_MAX, LLONG_MIN);
    }
private:
    bool isValid(TreeNode* root, long long maxval, long long minval){
        if(!root) return true;
        if(root->val>= maxval || root->val<=minval) return false;

        bool left= isValid(root->left, root->val, minval);
        bool right= isValid(root->right, maxval, root->val);
        return left && right;
    }
};