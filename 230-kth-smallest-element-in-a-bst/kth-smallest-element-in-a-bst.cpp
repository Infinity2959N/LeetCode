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
    vector<int> vals;
public:
    int kthSmallest(TreeNode* root, int k) {
        // Inorder traversal gives array in sorted form, we can use that
        traverse(root);
        return vals[k-1];
    }
private:
    void traverse(TreeNode* node){
        if(!node) return;

        traverse(node->left);
        vals.push_back(node->val);
        traverse(node->right);
    }
};