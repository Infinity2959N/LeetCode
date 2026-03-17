class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        // Data Structure: Sorting & Heap, Topic: Greedy, Pattern: Greedy with Regret
        // Sort based on distance (As position is sorted, we need to do nothing)
        // Base case: WE have enough fuel:
        if(startFuel>=target)   return 0;   // No stop was needed

        int currFuel= startFuel; // Accumulator for total fuel
        priority_queue<int> pq; // Memory to store all the "fuels" we have passed through.
        int i=0; // Index
        int stops=0; // Total stops made.
        
        int n= stations.size();

        while(currFuel< target){
            // 1. Absorb all stations we can reach
            while(i<n && stations[i][0]<= currFuel){
                pq.push(stations[i][1]);
                i++;
            }
            // 2. If we can't reach the next milestone and have no backups
            if(pq.empty())  return -1;

            // 3. Regret: Use the best station we passed
            currFuel+= pq.top(); pq.pop();
            stops++;
        }
        return stops;
    }
};