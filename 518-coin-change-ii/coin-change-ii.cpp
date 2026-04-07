class Solution {
public:
    int change(int amount, vector<int>& coins) {
        // Infinite coins: unbounded dp-> no reverse loop
        // Knapsack: from 0 to amount, try to find the ways a sum from givem denomination can be made
        vector<double> dp(amount+1, 0); // Init with 0 because 0 ways to make every sum with 0 coins
        dp[0]= 1; // One way to make sum of 0 using 0 coins

        for(auto coin: coins){
            for(int j= coin; j<=amount; j++){
                dp[j]+= dp[j-coin];
            }
        }
        return (int)dp[amount];
    }
};