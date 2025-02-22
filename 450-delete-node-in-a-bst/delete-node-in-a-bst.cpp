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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return root;

        // Step 1: Find the node and its location:
        if(root->val > key) {
            root->left = deleteNode(root->left, key);  // Update the left pointer
        }
        else if(root->val < key) {
            root->right = deleteNode(root->right, key);  // Update the right pointer
        }
        else {
            // Case 1: No children
            if(!root->left && !root->right) {
                return nullptr;
            }
            // Case 2: One child
            if(!root->left || !root->right) {
                return root->right ? root->right : root->left;
            }
            // Case 3: Both children (inorder successor)
            else {
                TreeNode* temp = root->right;
                while(temp->left) {
                    temp = temp->left;
                }
                // Replace root value with inorder successor's value
                root->val = temp->val;
                // Delete the inorder successor
                root->right = deleteNode(root->right, temp->val);
            }
        }
        
        return root;
    }
};
