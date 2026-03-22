class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m= grid.size(); // Row
        int n= grid[0].size(); // Column

        vector<int> dp(n);
        dp[0]= grid[0][0];
        for(int i=1; i< n; i++){
            dp[i]= grid[0][i]+ dp[i-1]; // Filling the first row. We can only go left to right.
        }

        for(int j=1; j<m; j++){
            dp[0]+= grid[j][0]; // For the first column, the value would be top+ curr
            for(int i=1; i<n; i++){
                dp[i]= grid[j][i]+ min(dp[i], dp[i-1]);
            }
        }
        return dp[n-1];
    }
};