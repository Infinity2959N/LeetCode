class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // not required to buy at lowest and sell at highest, when you can just sell at higher price, buy at that price again and sell it again if needed.
        // Aproach: Buy today and sell tomorrow if you can make profit, otherwise don't
        if(prices.size()<=1)    return 0;
        int profit=0;
        for(int i=1; i<prices.size(); i++){
            if(prices[i]> prices[i-1]){
                profit+= prices[i]-prices[i-1];
            }
        }
        return profit;
    }
};