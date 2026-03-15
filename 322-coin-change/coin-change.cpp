class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(), coins.end());
        int n= coins.size();
        vector<int> dp(amount+1, amount+1);  // Starting from 0, to make any amount, there is no way, so we will need infinite coins. As number of coins to make a sum cannot be more than the sum, we can emulate infinity using "amount+1"
        dp[0]= 0;   // 0 coins needed to make maount=0;

        for(int i=1; i<= amount; i++){
            for(int coin: coins){   //traverse till currAmount-1
                int diff= i-coin;
                if(diff< 0) break;

                dp[i]= min(dp[i], 1+dp[diff]);  // read comment for this logic
            }
        }
        return (dp[amount]< amount+1)? dp[amount]: -1;  
    }
};