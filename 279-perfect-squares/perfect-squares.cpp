class Solution {
public:
    int numSquares(int n) {
        vector<int> squares;
        for(int i=1; i*i<= n; i++){
            squares.push_back(i*i);
        }
        // Now that we have the array, it is just a simple unbounded knapsack dp problem (coin change)
        vector<int> dp(n+1, INT_MAX);
        dp[0]=0;

        for(int sq: squares){
            for(int i=1; i<=n; i++){    // i is target from 0 to n
                if(sq<=i){
                    dp[i]= min(dp[i], dp[i-sq]+1);
                }
            }
        }
        return dp[n];
    }
};