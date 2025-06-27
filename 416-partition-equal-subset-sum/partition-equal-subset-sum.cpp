class Solution {
public:
    bool canPartition(vector<int>& nums) {
        // Decoding the problem: subset sum1 should be equal to subset sum 2
        // What does that mean? ss1+ss2= total sum of array; meaning any one subset sum= total sum/2
        // Meaning: if we find a subset with sum= total/2, we return true
        // This made the problem a classic subset sum dp (0/1 knapsack)

        int total= accumulate(nums.begin(), nums.end(), 0);
        if(total%2==1)  return false; //odd total sum: equal partition not possible
        
        int target= total/2;
        int n= nums.size();

        vector<bool> dp(target+1 , false);
        dp[0]= true;

        for(int num: nums){
            for(int sum=target; sum>= num; sum--){
                dp[sum]= dp[sum] || dp[sum-num];
            }
        }

        return dp[target];
    }
};