class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        // Two variable optimization: Greedy boss question
        // If we pick the fastest, they might not be as efficient, if we pick the most efficient, they might not be fast.
        // Approach: Control the bottleneck. If we know the weakest link in terms of efficiency, we can greedily pick up fastest possible teammates that are at least as efficient as them.
        // Technique: *Sliding Floor*

        // Combine the pairs
        vector<pair<int, int>> engineers;
        for(int i=0; i<n; i++){
            engineers.push_back({efficiency[i], speed[i]});
        }
        //sort by efficiency descending
        sort(engineers.rbegin(), engineers.rend());

        // Min heap to keep track of largest speeds
        priority_queue<int, vector<int>, greater<int>> minHeap;
        long long speedSum=0;
        long long maxPerf=0;
        const int MOD= 1e9+7;

        for(auto& eng: engineers){
            int currEff= eng.first;
            int currSpeed= eng.second;

            // Add current speed to our sum
            speedSum+=currSpeed;
            minHeap.push(currSpeed);

            // If team size> k; "regret" the slowest member
            if(minHeap.size()>k){
                speedSum-= minHeap.top();
                minHeap.pop();
            }

            // Update Global Maximum
            maxPerf= max(maxPerf, speedSum*currEff);
        }
        return maxPerf% MOD;
    }
};