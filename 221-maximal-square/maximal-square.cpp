class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n= matrix.size(), m=matrix[0].size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

        int maxi=0;
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(matrix[i-1][j-1]=='1'){
                    int top= dp[i-1][j];
                    int up= dp[i][j-1];
                    int diagonal= dp[i-1][j-1];
                    
                    dp[i][j] = 1 + min({top, up, diagonal});
                    
                    maxi= max(maxi, dp[i][j]);
                }
            }
        }
        return maxi*maxi;   //need to return area
    }
};