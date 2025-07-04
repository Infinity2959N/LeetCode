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

/*
Four options at each node:
1. Take the node only
2. Take left path
3. Take right node
4. Take the entire left+node+right path. 
*/
class Solution {
    int globalMax= INT_MIN; // declaring in the scope of the class for access by all
public:
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return globalMax;
    }

private:
    int dfs(TreeNode* node){
        if(!node)   return 0;

        int left= max(0, dfs(node->left));
        int right= max(0, dfs(node->right));

        globalMax= max(globalMax, left+ node->val + right);

        return node->val+ max(left, right);    // We can't go both left and right as we eed to return a linear left/ right branch. Consider node to be left/right child of a parent node here
    }
};