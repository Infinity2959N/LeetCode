class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n= profits.size();

        vector<pair<int, int>> projects;
        for(int i=0; i<n; i++){
            projects.push_back({capital[i], profits[i]});
        }

        // Step 1: Sort by capital requirement
        sort(projects.begin(), projects.end());

        priority_queue<int> pq; //Max heap for profits

        int i=0;

        // Step 2: Perform K transactions
        while(k--){
            // Push all projects we can afford into the heap
            while(i<n && projects[i].first<=w){
                pq.push(projects[i].second);
                i++;
            }
            // If can't afford any new projects and heap is empty, we are stuck
            if(pq.empty()) break;

            // Step 3: Pick the most profitable project
            w+= pq.top();
            pq.pop();
        }
        return w;
    }
};