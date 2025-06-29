class Solution {
public:
    int jump(vector<int>& nums) {
        int farthest=0, currEnd= 0, n= nums.size(), jumps=0;

        for(int i=0; i<n-1; i++){
            farthest= max(farthest, nums[i]+i);
            if(i==currEnd){
                jumps++;
                currEnd= farthest;
                if(currEnd>= n) break;
            }
        }
        return jumps;
    }
};