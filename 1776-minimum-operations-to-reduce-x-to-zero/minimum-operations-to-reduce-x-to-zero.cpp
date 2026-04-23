class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        // Find the longest window that is equal to total sum-x, answer would be nums.size()-window_size;
        int n= nums.size();
        int sum= 0;
        for(int n: nums) sum+=n;
        int target= sum-x;
        if(target<0) return -1;

        int maxLen= -1, currSum=0;
    
        // Variable window: Expand->shrink->update
        int left=0, right=0;

        while(right<n){
            // Expand
            currSum+= nums[right];

            //Shrink: Too big currSum
            while(currSum> target && left<=right){
                currSum-=nums[left++];
            }

            // Compute
            if(currSum==target){
                maxLen= max(maxLen, right-left+1);
            }
            right++;
        }
        return (maxLen==-1)?-1: n-maxLen;
    }
};