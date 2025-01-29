class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        //use Floyd's tortoise and hare algorithm?
        int tortoise=nums[0], hare=nums[0], i=0, size=nums.size();
        
        //1. Find intersection point inside the cycle
        do{
            tortoise=nums[tortoise];    //move 1 step
            hare=nums[nums[hare]];  //move 2 steps
        }
        while(tortoise!=hare);

        //2. Find the entrance to the cycle:
        tortoise=nums[0];    //reset
        while(tortoise!=hare){
            tortoise=nums[tortoise]; //1 step
            hare=nums[hare];    //1 step
        }

        return tortoise;
    }
};