class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count=0;
        int candidate;
        for(auto num: nums){
            if(count==0){
                candidate=num;
                count++;
            }
            else if(num==candidate) count++;
            else count--;  
        }
        // No need to verify, if majority element definitely exists in the array, it would be the candidate
         return candidate;
    }
};