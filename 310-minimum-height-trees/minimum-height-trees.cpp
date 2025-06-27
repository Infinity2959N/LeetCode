class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==1)    return {0}; //edge case: single node
        vector<vector<int>> graph(n);
        vector<int> degree(n, 0);

        for(auto& edge: edges){
            int u= edge[0], v=edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
            degree[u]++;
            degree[v]++;
        }

        queue<int> leaves;
        for(int i=0; i<n; i++){
            if(degree[i]==1){
                leaves.push(i);
            }
        }

        while(n>2){
            int leafCount= leaves.size();
            n-= leafCount;

            for(int i=0; i<leafCount; i++){
                int leaf= leaves.front();
                leaves.pop();
                for(int neighbor: graph[leaf]){
                    degree[neighbor]--;
                    if(degree[neighbor]==1) leaves.push(neighbor);
                }
            }
        }

        //remaining nodes are roots of MHT
        vector<int> result;
        while(!leaves.empty()){
            result.push_back(leaves.front());
            leaves.pop();
        }
        return result;
    }
};