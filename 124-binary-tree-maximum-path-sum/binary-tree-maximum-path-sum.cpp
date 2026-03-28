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
    int maxSum= INT_MIN;    // Global tracker
public:
    int maxPathSum(TreeNode* root) {
        // For any node u, there are 2 paths that include u
        // 1. The rainbow: Starting from left subtree, goes through u, to right subtree
        // 2. The line: Path comes from parent, picks u, and bigger of left or right subtree

        // Strategy: Max tracker
        // We use a global (or class level) variable maxSum to keep track of rainbow path, while our recursion function only returns the line to the parent

        // Math: 
        // For each node: Left gain= max(0, dfs(node->left)), and similar for right. We use 0 for "clipping" if the value becomes negative. (Instead of taking a negative sum path, better not take a path at all)
        // The rainbow: node->val+ leftgain+ rightgain
        // The line: node->val+ max(leftgain, rightgain); what we send to parent
        solve(root);
        return maxSum;
    }
private:
    int solve(TreeNode* node){
        if(!node)   return 0;

        int leftgain= max(0, solve(node->left));
        int rightgain= max(0, solve(node->right));

        int currPathSum= node->val+ leftgain+ rightgain;    // rainbow sum
        maxSum= max(maxSum, currPathSum);

        return node->val+ max(leftgain, rightgain); // The Line
    }
};