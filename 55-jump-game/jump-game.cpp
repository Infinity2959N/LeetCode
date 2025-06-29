class Solution {
public:
    bool canJump(vector<int>& nums) {
        int farthest=0, n=nums.size();
        for(int i=0; i< n; i++){
            if(farthest >= n-1) return true;    //we can reach last index
            if(farthest< i) return false;   // Got stuck. We are processing a node we cannot reach
            int currFarthest= i+ nums[i];

            farthest= max(farthest, currFarthest);
        }

        return true;
    }
};