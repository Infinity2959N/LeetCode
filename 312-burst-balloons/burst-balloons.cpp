class Solution {
public:
    int maxCoins(vector<int>& nums) {
        // Logic: Instead of choosing first to burst, we choose last to burst
        // Why: if you burst baloon i, it's left and right are now neighbors. So, sub problems are now dependent on each other. This breaks the independent rule of dp
        // If we pick baloon k as the last one standing between a range of i and j, the neighbors for k would be i-1 and j+1, because every other baloon within the range has already been popped.
        // We pad the beginning and end by 1 to make it work

        // dp[i][j]= max(nums[i-1]*nums[k]*nums[j+1]+ dp[i][k-1]+ dp[k+1][j])

        int n= nums.size();
        // pad nums with 1
        vector<int> A(n+2, 1);
        for(int i=0; i<n; i++)  A[i+1]= nums[i];

        vector<vector<int>> dp(n+2, vector<int>(n+1, 0));

        for(int len=1; len<=n; len++){
            for(int i=1; i<= n-len+1; i++){
                int j= i+len-1;
                for(int k=i; k<=j; k++){
                    int curr= A[i-1]*A[k]*A[j+1]+ dp[i][k-1]+ dp[k+1][j];
                    dp[i][j]= max(dp[i][j], curr);
                }
            }
        }

        return dp[1][n];
    }
};