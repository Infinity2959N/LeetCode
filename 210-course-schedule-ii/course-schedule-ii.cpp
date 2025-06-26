class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        for(auto& pre: prerequisites){
            graph[pre[1]].push_back(pre[0]);
        }

        vector<int> visited(numCourses, 0);
        vector<int> result;

        for(int i=0; i<numCourses; i++){
            if(visited[i]==0){
                if(dfs(i, graph, visited, result)){
                    return {};  // Cycle detected. Cannot move forward
                }
            }
        }

        reverse(result.begin(), result.end());
        return result;
    }
private:
    bool dfs(int node, vector<vector<int>>& graph, vector<int>& visited, vector<int>& result){
        visited[node]=1;   //Visiting

        for(int neighbor: graph[node]){
            if(visited[neighbor]==1)    return true;
            if(visited[neighbor]==0){
                if(dfs(neighbor, graph, visited, result)) return true;
            }
        }

        visited[node]=2;   // Completely visited. Now will not be checked
        result.push_back(node);

        return false;
    }
};