class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        // 1 is land, 0 is water. Can't get to 0
        // Approach: starting at 0,0; traverse the grid, updating the array upon each traversal, replace 1 with 2, say
        // The number of times you encounter 1 in the graph upon iteration, is the number of islands
        int count= 0, m= grid.size(), n= grid[0].size();
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]=='1'){
                    count++;
                    traverse(grid, i, j, m, n);
                }
            }
        }
        return count;
    }
private: 
    void traverse(vector<vector<char>>& grid, int i, int j, int m, int n){
        if(i<0 || i>=m || j<0 || j>=n || grid[i][j]!='1') return;

        grid[i][j]='2';
        // Can go up, left, right or down
        traverse(grid, i-1, j, m, n);
        traverse(grid, i, j-1, m, n);
        traverse(grid, i+1, j, m, n);
        traverse(grid, i, j+1, m, n);
    }
};