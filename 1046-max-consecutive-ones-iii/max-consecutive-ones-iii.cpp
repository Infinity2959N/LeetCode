class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        // Approach: Treat atmost k 0s as 1, keep maximizing the window
        int countFlips=0;
        int left=0;
        int maxOnes=0;
        for(int right=0; right<nums.size(); right++){
            if(nums[right]==0)  countFlips++;
            while(countFlips>k){
                if(nums[left]==0){
                    countFlips--;
                }left++;
            }
            maxOnes= max(maxOnes, right-left+1);
        }
        return maxOnes;
    }
};