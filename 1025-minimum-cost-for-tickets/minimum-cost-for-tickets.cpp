class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        unordered_set<int> travellingDays(days.begin(), days.end());
        int lastDay= days.back(); //last value in days array

        vector<int> dp(lastDay+1, 0);
        dp[0]= 0;

        for(int i=1; i<=lastDay; i++){
            if(!travellingDays.count(i)){
                dp[i]= dp[i-1];
            }
            else{
                dp[i]= min({
                    dp[i-1]+costs[0],   // Case 1: we buy 1 day ticket
                    dp[max(0, i-7)]+ costs[1],  // Case 2: we bought 7 day ticket 7 days ago
                    dp[max(0, i-30)]+ costs[2]  // Case 3: we bought 30 day ticket 30 days ago
                });
            }
        }
        return dp[lastDay];
    }
};