class Solution {
public:
    int maxCoins(vector<int>& nums) {
        // MCM variant with padding:

        //Pad the array with 1 in both ends
        nums.insert(nums.begin(), 1);
        nums.push_back(1);

        int n= nums.size();
        //dp table:
        vector<vector<int>> dp(n, vector<int>(n, 0));

        // Fill DP table:
        for(int len=2; len<n; len++){   // len is distance b/w i and j
            for(int i=0; i+len <n; i++){
                int j= i+len;
                for(int k=i+1; k<j; k++){
                    dp[i][j]= max(
                        dp[i][j],
                        dp[i][k]+ dp[k][j]+ nums[i]*nums[k]*nums[j]
                    );
                }
            }    
        }
        return dp[0][n-1];
    }
};