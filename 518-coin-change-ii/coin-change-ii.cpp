class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n= coins.size();
        vector<vector<unsigned int>> dp(n+1, vector<unsigned int>(amount+1, 0)); // to prevent signed integer overflow
        
        //first row 1: as only 1 way to have 0 value: have no coins
        for(int i=0; i<=n; i++){
            dp[i][0]= 1;
        }

        // Two options now: Use coin or don't use coin
        for(int i=1; i<=n; i++){
            for(int j=1; j<=amount; j++){
                dp[i][j]= dp[i-1][j];   //don't use coin
                if(j >= coins[i-1])     // base case handling: amount>= denomination of the coin
                    dp[i][j]+= dp[i][j-coins[i-1]];     //use coin
            }
        }

        return dp[n][amount];
    }
};

/*
Space optimised way:
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount + 1, 0);
        dp[0] = 1;  // Base case: one way to make amount 0

        for (int coin : coins) {
            for (int j = coin; j <= amount; ++j) {
                dp[j] += dp[j - coin];
            }
        }

        return dp[amount];
    }
};

*/