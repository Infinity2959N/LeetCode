class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //1, Build the adjacency list
        vector<vector<int>> graph(numCourses);
        for(auto &pre: prerequisites){
            graph[pre[1]].push_back(pre[0]);  // pre[1] → pre[0]
        }

        // Step 2: Visited state array
        vector<int> visited(numCourses, 0);  // 0 = unvisited, 1 = visiting, 2 = visited

        for(int i=0; i<numCourses; i++){
            if(visited[i]==0 && hasCycle(i, graph, visited)){   //check for cycle for non processed nodes, if processed skip.
                return false; 
            }
        }
        return true;
    }
private:
    bool hasCycle(int node, const vector<vector<int>>& graph, vector<int>& visited){
        visited[node]= 1;
        for(int neighbour: graph[node]){
            if(visited[neighbour]==1)   return true;

            if(visited[neighbour]==0){
                if(hasCycle(neighbour, graph, visited))
                    return true;
            }
        }
        visited[node]= 2;   //fully processed
        return false;
    }
};