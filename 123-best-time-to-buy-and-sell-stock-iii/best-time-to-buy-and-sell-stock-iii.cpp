class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // State machine DP
        int hold1= INT_MIN; //Profit when buying first stock, will be negative as we haven't earned anything
        int release1=0; // Profit after we sell first stock
        int hold2= INT_MIN; // Profit when buying second stock
        int release2=0;

        for(int price: prices){
            // Sell second: either sell or hold
            release2= max(release2, hold2+ price);

            // Buy second: either keep previous or buy now by spending price
            hold2= max(hold2, release1- price);

            // Sell first: either sell or hold
            release1= max(release1, hold1+ price);

            // Buy first: either keep previous or buy now at current cost (-price)
            hold1= max(hold1, -price);
        }

        //result in release 2:
        return release2;
    }
};