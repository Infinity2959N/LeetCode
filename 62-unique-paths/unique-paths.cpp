class Solution {
public:
    int uniquePaths(int m, int n) {
        //memoization
        vector<vector<int>> dp(m, vector<int>(n, -1));
        //bottom up
        return solveDP(m-1, n-1, dp);
    }
private: 
    int solveDP(int i, int j, vector<vector<int>>& dp){
        if(i==0 || j==0)    return 1;
        if(dp[i][j]!= -1)   return dp[i][j];
        // dp[i][j]= going up+ going left
        return dp[i][j]= solveDP(i-1, j, dp)+ solveDP(i, j-1, dp);
    }
};