/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    unordered_map<TreeNode*, TreeNode*> parentMap;

    void findParents(TreeNode* node, TreeNode* parent){
        if(!node) return;
        parentMap[node]= parent;
        findParents(node->left, node);
        findParents(node->right, node);
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        // Approach: If it were a graph question, it was a straightforward bfs starting from target node moving k steps
        // So, we make this tree a graph then, how? We track parents using dfs so that we can go back up
        // Then it's standard BFS (with a visited set), and we return the whole queue after k steps

        findParents(root, nullptr);
        queue<TreeNode*> q;
        q.push(target);

        unordered_set<TreeNode*> visited;
        visited.insert(target);

        int currLevel=0;

        while(!q.empty() && currLevel<k){
            int size= q.size();
            for(int i=0; i<size; i++){
                TreeNode* curr= q.front(); q.pop();
                vector<TreeNode*> neighbors= {curr->left, curr->right, parentMap[curr]};
                for(auto neighbor: neighbors){
                    if(neighbor && !visited.count(neighbor)){
                        visited.insert(neighbor);
                        q.push(neighbor);
                    }
                }
            }
            currLevel++;
        }
        if(q.empty()) return {};
        vector<int> values;
        while(!q.empty()){
            TreeNode* node= q.front(); q.pop();
            values.push_back(node->val);
        }
        return values;
    }
};