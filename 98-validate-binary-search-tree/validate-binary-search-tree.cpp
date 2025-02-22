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
          if(!root) return true;

          return checkValid(root, LONG_MIN, LONG_MAX);
    }
private:
    bool checkValid(TreeNode* root, long min_val, long max_val){
        if(!root)   return true;

        if(root->val <= min_val || root->val >= max_val)  return false;

        return checkValid(root->left, min_val, root->val) && 
               checkValid(root->right, root->val, max_val);
    }
};