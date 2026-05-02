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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        // We have row and columns: for a node, left is at (row+1, col-1) and right at (row+1, col+1), we have to return them in order of cols: Like all in col=-1, then all in col= 0, .... Sort by col, if same col, then by row, if same row, then by value
        // Data structure to use: map<map<multiset>> Then it's simple BFS/DFS (BFS preferred to preserve order better)
        map<int, map<int, multiset<int>>> nodes;

        queue<pair<TreeNode*, pair<int, int>>> q;   // {node, {row, col}}

        q.push({root, {0,0}});

        while(!q.empty()){
            auto temp = q.front();
            q.pop();
            TreeNode* node = temp.first;
            int row = temp.second.first;
            int col = temp.second.second;

            nodes[col][row].insert(node->val); // Automatic sorting

            if (node->left) q.push({node->left, {row + 1, col - 1}});
            if (node->right) q.push({node->right, {row + 1, col + 1}});
        }

        vector<vector<int>> ans;

        for(auto &col: nodes){
            vector<int> temp;
            for(auto& row: col.second){
                temp.insert(temp.end(), row.second.begin(), row.second.end());
            }
            ans.push_back(temp);
        }
        return ans;
    }
};