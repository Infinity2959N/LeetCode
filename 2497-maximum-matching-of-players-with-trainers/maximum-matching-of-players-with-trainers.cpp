class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        if(players.empty() || trainers.empty()) return 0;
        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());

        int i=0, j=0, s1= players.size(), s2= trainers.size();

        while(i< s1 && j<s2){
            if(trainers[j++] >= players[i]){
                i++;
            }
        }
        return i;
    }
};