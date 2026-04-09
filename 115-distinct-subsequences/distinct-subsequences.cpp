class Solution {
public:
    int numDistinct(string s, string t) {
        // LCS with counting (similar to knapsack)
        // On match: 2 choices: Count it, or ignore it
        // On no match: no choice except ignoring
        int n= s.size(), m= t.size();

        vector<unsigned long long>dp(m+1, 0);   // dp[j]= number of ways to form t[0->j-1]
        dp[0]= 1;

        for(int i=1; i<=n; i++){
            // Reverse loop to prevent using updated values
            for(int j=m; j>=1; j--){
                if(s[i-1]==t[j-1]){
                    //total ways= ways including s[i-1] and excluding s[i-1]
                    dp[j]= dp[j-1]+ dp[j];
                }
            }
        }
        return (int)dp[m];
    }
};