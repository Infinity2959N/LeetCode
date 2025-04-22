class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        // This code will use multi source BFS
        // In a multi source BFS, we insert all the "rotten oranges" in the queue initially.
        int rows= grid.size();
        int cols= grid[0].size();
        
        queue<pair<int, int>> q;
        
        int fresh=0;
        
        for(int r=0; r< rows; r++){
            for(int c=0; c< cols; c++){
                if(grid[r][c]==2){
                    q.push({r,c});  // Queue stores the index (that is row and column).
                }else if(grid[r][c]==1){
                    fresh++;
                }
            }
        }

        return bfs(grid, q, fresh);
    }
private:
    int bfs(vector<vector<int>>& grid, queue<pair<int, int>>& q, int freshCount){
        int rows= grid.size();
        int cols= grid[0].size();

        int minutes=0;

        vector<pair<int, int>> directions={{0,1}, {1,0}, {0,-1}, {-1, 0}}; //right, down, left, up
        while(!q.empty() && freshCount > 0){
            int levelSize=q.size();

            for(int i=0; i<levelSize; i++){
                auto [r,c]= q.front();
                q.pop();
                for(auto [dr, dc]: directions){
                    int nr= r+dr;   //next row 
                    int nc= c+dc;   //net column
                    // Adding the direction to rows and columns to move across all the 4 directions.
                    if(nr>=0 && nr< rows    &&    nc>=0 && nc< cols    &&    grid[nr][nc]==1){
                        grid[nr][nc]=2; //rot it!
                        freshCount--;
                        q.push({nr, nc});
                    }
                }
            }
            minutes++; // For every level +1 minute. (Not for every single rotten, but for a level!)
        }
        return (freshCount==0)? minutes: -1;
    }
};