struct Job{
    int start, end, profit;
};

class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        // sorting+ dp+ binary search
        int n= startTime.size();
        vector<Job> jobs(n);
        for(int i=0; i<n; i++) jobs[i]={startTime[i], endTime[i], profit[i]};

        sort(jobs.begin(), jobs.end(), [](const Job&a, const Job&b){
            return a.end< b.end;
        });

        // dp[i]= max profit considering the first i jobs
        vector<int> dp(n);
        dp[0]= jobs[0].profit;

        for(int i=1; i<n; i++){
            // option 1: Don't include current job
            int currProfit= jobs[i].profit;

            // option 2: Include current job and last compatible job
            // Binary search for last job that ends<=curr job's start
            int l = 0, r = i - 1, lastIdx = -1;
            while(l <= r) {
                int mid = l + (r - l) / 2;
                if(jobs[mid].end <= jobs[i].start) {
                    lastIdx = mid;
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
            if(lastIdx!= -1) currProfit+= dp[lastIdx];

            dp[i]= max(dp[i-1], currProfit);
        }
        return dp[n-1];
    }
};