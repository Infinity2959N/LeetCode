class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        // Greedy (sorting) with Regret (max heap)

        // Step 1: Sort by deadline
        sort(courses.begin(), courses.end(), [](auto& a, auto& b){
            return a[1]< b[1];
        });

        priority_queue<int> pq; // Max heap to store duratins of courses taken
        int totalTime=0;

        for(auto& c: courses){
            int duration= c[0], deadline= c[1];
            if(duration> deadline) continue;    // Skip impossible courses
            totalTime+=duration;
            pq.push(duration);

            // Regret step: If oveshot the deadline, ditch the longest course
            if(totalTime> deadline){
                totalTime-= pq.top();
                pq.pop();
            }
        }
        return pq.size();
    }
};