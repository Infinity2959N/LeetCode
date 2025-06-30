class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int n= costs.size();    // We shall consider n instead of 2n for simplicity sake

        sort(costs.begin(), costs.end(), [](const vector<int>& a, const vector<int>& b){
            return (a[0]-a[1])< (b[0]-b[1]);
        });

        int totalCost= 0;

        for(int i=0; i<n/2; i++){   // First n/2 elements have cheaper a
            totalCost+= costs[i][0];
        }
        for(int i=n/2; i<n; i++){   // Last n/2 elements have cheaper b
            totalCost+= costs[i][1];
        }

        return totalCost;
    }
};