class Solution {
public:
    int longestPalindromeSubseq(string s) {
        // Trick: LCS(s, s_reverse)
        // Hard way (The pattern): Interval DP
        // Diagonals= init with 1 (Each is palindrome with itself)
        // Match: dp[i][j]= dp[i+1][j-1]+2
        // Not match: dp[i][j]= max(dp[i+1][j], dp[i][j-1])
        int n= s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for(int i=0; i<n; i++){
            dp[i][i]= 1;
        }

        for(int len=2; len<=n; len++){    // Iterate over interval length from 2 to n
            for(int i=0; i<=n-len; i++){
                int j= i+len-1;
                if(s[i]==s[j]){
                    dp[i][j]= dp[i+1][j-1]+2;
                }else{
                    dp[i][j]= max(dp[i][j-1], dp[i+1][j]);
                }
            }

        }
        return dp[0][n-1];
    }
};