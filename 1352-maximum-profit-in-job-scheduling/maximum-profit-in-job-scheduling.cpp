class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<tuple<int, int, int>> jobs;   //startTime, endTime, profit
        int n= startTime.size();
        for(int i=0; i<n; i++){
            jobs.push_back({startTime[i], endTime[i], profit[i]});
        }

        // Sort based on end time:
        sort(jobs.begin(), jobs.end(), [](const auto& a, const auto& b) {
            return get<1>(a) < get<1>(b);   //sort based on end time. 
            //get<x>(tuple) gets the xth index element of tuple
        });

        vector<pair<int, int>> dp= {{0,0}}; // dp= {end time, max profit till now}, initialized with dummy job

        for(int i=0; i<n; i++){
            int currStart = get<0>(jobs[i]);
            int currEnd = get<1>(jobs[i]);
            int currProfit = get<2>(jobs[i]);

            // Binary search for last job in dp with endTime <= currStart
            int l = 0, r = dp.size() - 1, idx = 0;
            while (l <= r) {
                int mid = l + (r - l) / 2;
                if (dp[mid].first <= currStart) {
                    idx = mid;  // potential match
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }

            int take = currProfit + dp[idx].second;
            int skip = dp.back().second;

            dp.push_back({currEnd, max(take, skip)});
        }

        return dp.back().second;
    }
};