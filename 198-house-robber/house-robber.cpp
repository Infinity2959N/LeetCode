class Solution {
public:
    int rob(vector<int>& nums) {
        int n= nums.size();
        vector<int> dp(n, -1);

        return robber(nums, n-1, dp);
    }
private:
    int robber(const vector<int>& nums, int n, vector<int>& dp){
        //base case:
        if(n<0){
            return 0;
        }
        if(dp[n]!=-1){
            return dp[n];
        }

        int choose= nums[n]+ robber(nums, n-2, dp);
        int skip= 0+ robber(nums, n-1, dp);

        return dp[n]= max(choose, skip);
    }
};