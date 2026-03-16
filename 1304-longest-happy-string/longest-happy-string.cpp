class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        // Data Structure: Heap, Topic: Greedy, Pattern: Intervals
        // Approach: Add the most frequent atmost 2 times, then second most frequent, and push the most frequent back in heap
        // Complexity: O(nlog3)= O(n)

        priority_queue<pair<int, char>> pq;
        if(a>0)pq.push({a, 'a'});
        if(b>0)pq.push({b, 'b'});
        if(c>0)pq.push({c, 'c'});

        string res="";

        while(!pq.empty()){
            // Check the last 2 of the res
            // 2 cases:
            // Case A: If top char doesn't match last 2, use it once and update the frequency
            // Case B: If it makes a triple pair, pop it, use the second best option (current top) and push it back in after updating the current top. If no second best, break
            auto[f1, c1]= pq.top(); pq.pop();
            int n= res.length();
            // Check for triple
            if(n>=2 && res[n-1]==c1 && res[n-2]==c1){
                if(pq.empty())   break;
                // Use second best option
                auto[f2, c2]= pq.top(); pq.pop();
                res+= c2;
                if(--f2> 0) pq.push({f2, c2});
                // Push the first pair back in
                pq.push({f1, c1});
            }else{
                // Safe to use the top
                res+= c1;
                if(--f1> 0) pq.push({f1, c1});
            }

        }
        return res;
    }
};