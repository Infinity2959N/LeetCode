class Solution {
public:
    bool canJump(vector<int>& nums) {
        // The greedy approach is to try to jump as far as possible
        int farthest=0, n= nums.size();

        for(int i=0; i< n; i++){
            int num= nums[i];
            if(i > farthest) return false;  //cannot reach at i
            farthest= max(num+i, farthest);
            if(farthest >= n-1)   return true;
        }
        return false;
    }
};