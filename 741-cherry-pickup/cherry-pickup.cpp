class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        /*
        Cell: 0-> pass
              1-> Pick cherry and pass
             -1-> Thorn; cannot pass
        Rules: Start at (0,0), reach (n-1, n-1)
               From (n-1,n-1), return back to (0,0)
               When you collect a cherry, the cell becomes 0
        if no valid path, no cherries can be collected
        */

        // intuition: Treat it as two people walking down to pick cherries
        /* If two people start at 0,0 and move toward (n-1, n-1), after k steps:
            person 1 at (r1,c1); person 2 at (r2,c2)
            as r1+c1=k and r2+c2=k, we don't need to track (r1,c1,r2,c2,k), we can just track (r1,r2,k)
            At each step k, both can move dowm or right, giving us 4 possible previous states: rr, dr, rd, dd
            if both at same step,  pick cherry only once
            k is number of moves, for each move made right or down, you move exactly 1 unit away from origin, hence r1+c1=k
        */
        int n= grid.size();
        vector<vector<int>>dp(n, vector<int>(n, -1e9));
        dp[0][0]= grid[0][0];
        if(grid[0][0]==-1) return 0; 
        //k= total steps (r+c)
        for(int k=1; k<= 2*n-2; k++){
            //backward loops to prevent using updated values
            for(int r1= n-1; r1>=0; r1--){
                for(int r2= n-1; r2>=0; r2--){
                    int c1= k-r1, c2= k-r2;

                    // boundary and thorn check
                    if(c1<0 || c1>= n || c2<0 || c2>=n || grid[r1][c1]==-1 || grid[r2][c2]==-1){
                        dp[r1][r2]= -1e9;
                        continue;
                    }

                    int cherries= (r1==r2)? grid[r1][c1]: grid[r1][c1]+ grid[r2][c2];

                    // The 4 transitions
                    int res= dp[r1][r2];// Right-Right (r1, r2 haven't changed)
                    if (r1 > 0) res = max(res, dp[r1-1][r2]); // Down-Right
                    if (r2 > 0) res = max(res, dp[r1][r2-1]); // Right-Down
                    if (r1 > 0 && r2 > 0) res = max(res, dp[r1-1][r2-1]); // Down-Down
                    
                    dp[r1][r2]= (res>=0)? res+cherries: -1e9;
                }
            }
        }
        return max(0, dp[n-1][n-1]);
    }
};