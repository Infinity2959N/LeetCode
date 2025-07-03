class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if (n == 0 || k == 0) return 0;

        // dp[day][transactions][holding]
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(k + 1, vector<int>(2, 0)));

        // Initialization for day 0
        for (int t = 0; t <= k; ++t) {
            dp[0][t][0] = 0;              // not holding anything on day 0
            dp[0][t][1] = -prices[0];     // bought stock on day 0
        }

        for (int day = 1; day < n; ++day) {
            for (int t = 1; t <= k; ++t) {
                // Not holding: either continue not holding, or sell today
                dp[day][t][0] = max(dp[day - 1][t][0], dp[day - 1][t][1] + prices[day]);

                // Holding: either continue holding, or buy today (uses one transaction)
                dp[day][t][1] = max(dp[day - 1][t][1], dp[day - 1][t - 1][0] - prices[day]);
            }
        }

        // Find max profit on last day with 0 stock in hand
        int maxProfit = 0;
        for (int t = 0; t <= k; ++t) {
            maxProfit = max(maxProfit, dp[n - 1][t][0]);
        }

        return maxProfit;
    }
};
