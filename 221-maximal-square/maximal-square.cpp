class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        // DP formula: if val==1-> 1+ min(top, left, diagonal)
        int m= matrix.size();   // rows
        int n= matrix[0].size();    // columns

        int diag=0, maxi=0;
        vector<int> dp(n);
        for(int j=0; j<n; j++){
            dp[j]= matrix[0][j]-'0';
            maxi= max(dp[j], maxi);
        }

        for(int i=1; i<m; i++){ //rows
            diag= dp[0];    // Diagonal for next element of top+1th row
            dp[0]= matrix[i][0]-'0';
            maxi= max(dp[0], maxi);
            for(int j=1; j< n; j++){
                int temp= dp[j];
                if(matrix[i][j]=='1'){
                    dp[j]= 1+ min({dp[j], dp[j-1], diag});
                    maxi= max(dp[j], maxi);
                }else{
                    dp[j]=0;
                }
                diag= temp;
            }
        }
        return pow(maxi,2);
    }
};