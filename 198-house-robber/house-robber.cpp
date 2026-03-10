class Solution {
public:
    int rob(vector<int>& nums) {
        // Two choices at each step: rob or don't rob
        vector<int> dp(nums.size());
        if(nums.size()==1)  return nums[0];
        dp[0]= nums[0];
        dp[1]= max(dp[0], nums[1]);

        for(int i=2; i<nums.size(); i++){
            dp[i]= max(dp[i-1], nums[i]+dp[i-2]);
        }
        return dp[nums.size()-1];
    }
};