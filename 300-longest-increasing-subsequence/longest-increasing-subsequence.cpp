class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        // Pattern: Non constant transition

        int n= nums.size();
        vector<int> dp(n, 1);   // Each makes a subsequene with itself
        for(int i=1; i<n; i++){
            for(int j=0; j<i; j++){
                if(nums[j]< nums[i]){
                    dp[i]= max(dp[i], dp[j]+1);
                }
            }
        }
        int maxi=1;
        for(int n: dp){
            maxi= max(maxi, n); 
        }
        return maxi;
    }
};