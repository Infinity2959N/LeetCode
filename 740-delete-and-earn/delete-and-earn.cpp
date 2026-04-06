class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        // Major hint: If you take a number, better take all of the occurences.But taking a number means you can't take a number lower or higher than it. 
        // DP choice: Do we take the number or do we skip it.
        // If take it, score adds up, but skipping might help in score if the adjacent numbers had higher score.

        // Approach: House robber in disguise: Create an array of frequency, index is the number. For an index i, you can't take i+1 and i-1

        int n= nums.size();
        int maxi= *max_element(nums.begin(), nums.end());
        vector<int> frequency(maxi+1);
        for(int num: nums){
            frequency[num]++;
        }

        // Now, house robber on scores
        // Optimized DP: 2 variables: one for i-2 and i-1
        //base case:
        int prev2= 0;   // dp[0], equivalent to i-2
        int prev1= frequency[1];    // dp[1], equivalent to i-1
    
        for(int i=2; i<= maxi; i++){
            int curr= max((prev2+ i*frequency[i]), prev1);
            prev2= prev1;
            prev1= curr;
        }
        return prev1;
    }
};