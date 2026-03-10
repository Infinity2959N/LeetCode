class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        // Take min cost from last 2 stairs
        int n= cost.size();
        int min1=cost[0];
        int min2=cost[1];

        for(int i=2; i<n; i++){
            int currMin= min(min1, min2)+ cost[i];
            min1= min2;
            min2= currMin;
        }
        return min(min1, min2);
    }
};