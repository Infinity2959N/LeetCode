class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());

        int i=0, j=0, s1= players.size(), s2= trainers.size();

        while(i< s1 && j< s2){
            if(trainers[j++] >= players[i]){
                i++;
            }
        }
        return i;
    }
};