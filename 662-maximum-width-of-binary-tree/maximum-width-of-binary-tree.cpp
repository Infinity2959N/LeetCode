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
    int widthOfBinaryTree(TreeNode* root) {
        // Levelwise traversal: BFS
        // For a parent at index i, left child is at 2*i+1, right child at 2*i+2
        // For last level, return endidx-startidx+1
        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0});

        long long maxDepth=0;
        while(!q.empty()){
            int size= q.size();
            long long minIndex= q.front().second;
            long long first, last;

            for(int i=0; i<size; i++){
                long long curr_idx= q.front().second- minIndex;     // Normalize
                TreeNode* curr= q.front().first;
                q.pop();
                if(i==0) first= curr_idx;
                if(i==size-1) last= curr_idx;

                if(curr->left) q.push({curr->left, 2*curr_idx+1});
                if(curr->right) q.push({curr->right, 2*curr_idx+2});
            }
            maxDepth= max(maxDepth, last-first+1);
        }
        return (int)maxDepth;
    }
};