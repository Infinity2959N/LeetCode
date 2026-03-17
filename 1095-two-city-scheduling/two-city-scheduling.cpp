class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        // sort based on difference in costs, if cost of a is the cheapest, send to A, if it's most expensive, send to b. We don't look at what's cheaper, but rather at how much we save
        sort(costs.begin(), costs.end(), [](const vector<int>& a, const vector<int>& b){
            return (a[0]-a[1])< (b[0]-b[1]);
        });
        // a[0]-a[1] is how much cheaper is going to city a than going to city b. THe lesser the better.
        int cost=0;
        for(int i=0; i<costs.size()/2; i++){
           cost+= costs[i][0];
        }
        for(int i=costs.size()/2; i<costs.size(); i++){
            cost+= costs[i][1];
        }
        return cost;
    }
};