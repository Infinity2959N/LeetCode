class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(players.begin(), players.end(), greater<>());
        sort(trainers.begin(), trainers.end(), greater<>());

        int j=0;

        for(int i=0; i<players.size(); i++){
            if(j<trainers.size() && players[i]<=trainers[j]){
                j++;
            }
        }
        return j;
    }
};