class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());
        int iceCreams=0;
        for(int cost: costs){
            if(coins<cost) break;
            coins-= cost;
            iceCreams++;
        }
        return iceCreams;
    }
};