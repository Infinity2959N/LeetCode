class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        // Step 1: sort based on ages, for same age we can sort by scores
        vector<pair<int, int>> players;
        for(int i=0; i<scores.size(); i++){
            players.push_back({ages[i], scores[i]});
        }    

        sort(players.begin(), players.end());
        vector<int> dp(scores.size(), 0);
        int ans=0;

        // LIS logic
        for(int i=0; i<scores.size(); i++){
            dp[i]= players[i].second;
            for(int j=0; j<i; j++){
                if(players[j].second<= players[i].second)   // younger player cannot have higher score
                    dp[i]= max(dp[i], dp[j]+ players[i].second);
            }
            ans= max(ans, dp[i]);
        }
        return ans;
    }   
};