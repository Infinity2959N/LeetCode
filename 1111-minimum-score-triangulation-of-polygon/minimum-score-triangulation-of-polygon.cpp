class Solution {
public:
    int minScoreTriangulation(vector<int>& values) {
        int n= values.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        // if length is 2: value=0, as traingle with 2 edges is not possible

        // gap between i and j must be atleast 2
        for(int len=2; len< n; len++){
            for(int i=0; i+len< n; i++){
                int j= i+len;
                dp[i][j]= INT_MAX;

                // Try every k between i and j
                for(int k= i+1; k<j; k++){
                    int currScore= values[i]*values[k]*values[j]+ dp[i][k]+ dp[k][j];
                    dp[i][j]= min(dp[i][j], currScore);
                }
            }
        }
        return dp[0][n-1];
    }
};