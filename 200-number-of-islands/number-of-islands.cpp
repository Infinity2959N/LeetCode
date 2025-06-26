class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m= grid.size();
        int n= grid[0].size();
        int countIslands=0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]=='1'){
                    countIslands++;
                    DFS(grid, i, j, m, n);
                }
            }
        }
        return countIslands;
    }
private:
    void DFS(vector<vector<char>>& grid, int i, int j, int m, int n){
        if(i<0 || i>=m || j<0 || j>=n || grid[i][j]=='0')   return;
        
        if(grid[i][j]=='1') grid[i][j]='0';

        DFS(grid, i-1, j, m, n);
        DFS(grid, i+1, j, m, n);
        DFS(grid, i, j-1, m, n);
        DFS(grid, i, j+1, m, n);
    }
};