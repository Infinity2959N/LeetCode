class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n= grid[0].size();
        vector<int> dp(n, 0);

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(i==0 && j==0)    dp[j]= grid[i][j];  // starting cell
                else{
                    int up= (i>0)? dp[j]: INT_MAX;
                    int left= (j>0)? dp[j-1]: INT_MAX;
                    dp[j]= grid[i][j]+ min(up, left);
                }
            }
        }
        return dp[n-1];
    }
};