class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        // Approach: same as flood fill, we have to return number of 1's not connected by border
        // DFS on every 1's found while iterating on the border, change to 0, return 1s left in the end

        int m= grid.size(), n= grid[0].size();

        // Move through the first and last row:
        for(int i=0; i<m; i++){
            if(grid[i][0]==1)   dfs(grid, i, 0, m, n);
            if(grid[i][n-1]==1)   dfs(grid, i, n-1, m, n);
        }
        // Move through the first and last column:
        for(int i=0; i<n; i++){
            if(grid[0][i]==1)   dfs(grid, 0, i, m, n);
            if(grid[m-1][i]==1)   dfs(grid, m-1, i, m, n);
        }

        int count=0;

        //iterate through the entire matrix to count the number of 1's left
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==1)   count++;
            }
        }
        return count;
    }
private:
    void dfs(vector<vector<int>>& grid, int i, int j, int m, int n){
        // Base case: Either Out of bounds or 0:
        if(i<0 || i>=m || j<0 || j>=n || grid[i][j]==0)  return;
        grid[i][j]=0;
        // Call dfs on left, right, up and down
        dfs(grid, i+1, j, m, n);
        dfs(grid, i-1, j, m, n);
        dfs(grid, i, j+1, m, n);
        dfs(grid, i, j-1, m, n);
    }
};