class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        // Approach:
        // Step 1: Sort on last dates, so that we are always picking one with less end dates first
        // Step 2: use max heap to track duration of courses we have taken so far

        sort(courses.begin(), courses.end(), [](const vector<int>& a, const vector<int>& b){
            return a[1]< b[1]; 
        });

        priority_queue<int> maxHeap;
        int totalTime=0;

        for(auto& course: courses){
            int duration= course[0];
            int deadline= course[1];

            totalTime+= duration;
            maxHeap.push(duration);

            // Exceeded the current course deadline
            if(totalTime> deadline){
                totalTime-= maxHeap.top();
                maxHeap.pop();
            }
        }

        return maxHeap.size();
    }
};