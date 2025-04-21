class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n= isConnected.size();
        int count=0;
        vector<int> visited(n, 0);
        for(int i=0; i<n; i++){
            if(!visited[i]){
                count++;
                DFS(isConnected, i, visited);
            }
        }
        return count;
    }
private:
    void DFS(vector<vector<int>>& isConnected, int node, vector<int>& visited){        
        visited[node]= 1;
        for(int i=0; i< isConnected.size(); i++){
            if(isConnected[node][i] && !visited[i]){
                DFS(isConnected, i, visited);
            }
        }
    }
};