class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n= graph.size();

        vector<int> color(n,-1);    // vector to store the color of the graph

        // Approach: BFS+ 2 coloring, ensure adjacent nodes have different colors
        for(int i=0; i<n; i++){
            if(color[i]!= -1) continue; //already visited
            queue<int> q;
            q.push(i);
            color[i]=0; //start with 0;
            while(!q.empty()){
                int node= q.front();
                q.pop();
                for(int neighbor: graph[node]){
                    if(color[neighbor]==-1){
                        color[neighbor]= 1- color[node];
                        q.push(neighbor);
                    }
                    else if(color[neighbor]==color[node])
                        return false;
                }
            }
        }
        return true;
    }
};