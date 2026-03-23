class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        // We keep track of two things: Length and count of ways to get that length
        // When i looks at j, there are 3 cases: 
        // A: Bigger Sequence: dp[i]= dp[j]+1 and count[i]= count[j]
        // B: Tie: (dp[j]+1== dp[i])    dp[i] stays same, but count[i]+= count[j]
        // C: Smaller: Ignore

        // Todo: 1. Find the LIS 2. Sum all value in count, where for every i, dp[i]= max

        int n= nums.size();
        if(n==1)    return 1;
        vector<int> dp(n, 1);
        vector<int> count(n, 1);    // always 1 way to make an LIS of size 1 for each element

        for(int i=1; i<n; i++){
            for(int j=0; j<i; j++){
                if(nums[i]> nums[j]){
                    if(dp[j]+1> dp[i]){ // Case A
                        dp[i]= dp[j]+1;
                        count[i]= count[j];
                    }else if(dp[j]+1== dp[i]){
                        count[i]+=count[j];
                    }
                }
            }
        }
        int maxElement= *max_element(dp.begin(), dp.end());
        int sum=0;
        for(int i=0; i<n; i++){
            if(dp[i]==maxElement)   sum+=count[i];
        }
        return sum;
    }
};