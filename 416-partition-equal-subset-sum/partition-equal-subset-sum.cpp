class Solution {
public:
    bool canPartition(vector<int>& nums) {
        // Knapsack Problem
        // Fill one knapsack to half of total sum
        int totalSum=0;
        for(int i=0; i<nums.size(); i++){
            totalSum+= nums[i];
        }
        if(totalSum%2==1) return false;
        totalSum/=2;
        vector<int> dp(totalSum+1, 0);
        dp[0]=1;

        for(int num: nums){
            for(int i=totalSum-num; i>=0; i--){
                if(dp[i]){
                    dp[i+num]= 1;
                }
            }
        }
        return dp[totalSum];
    }
};