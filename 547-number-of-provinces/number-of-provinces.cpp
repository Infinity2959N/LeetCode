class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n= isConnected.size();
        int count=0;
        vector<bool> visited(n, false);
        for(int i=0; i<n; i++){
            if(!visited[i]){
                count++;
                DFS(isConnected, i, visited);
            }
        }
        return count;
    }
private:
    void DFS(vector<vector<int>>& isConnected, int node, vector<bool>& visited){        
        visited[node]= true;
        for(int i=0; i< isConnected.size(); i++){
            if(isConnected[node][i] && !visited[i]){
                DFS(isConnected, i, visited);
            }
        }
    }
};