class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty())  return 0;
        unordered_set<int> numSet(nums.begin(), nums.end());
        int count=0;
        for(int num: numSet){
            //Check if a number smaller than current by 1 exists:
            if(numSet.count(num-1)==0){
                int currCount=1;    //As current element will be the first element of the sequence
                while(numSet.count(num+currCount)){
                    currCount++;
                }
                count= max(count, currCount);
            }
        }
        return count;
    }
};