int majorityElement(int* nums, int numsSize) {
    //using Moore Voting:
    int count=0,candidate=-1;
    for(int i=0;i<numsSize;i++){
        if(count==0)    candidate=nums[i];
        if(nums[i]==candidate)  count++;
        else count--;
    }
    return candidate;
}