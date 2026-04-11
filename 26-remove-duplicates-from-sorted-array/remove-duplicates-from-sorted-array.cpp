class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n= nums.size();
        unordered_set<int> seen;
        int curr=0;
        for(int i=0; i<n; i++){
            if(!seen.count(nums[i])){
                seen.insert(nums[i]);
                nums[curr++]= nums[i];
            }
        }
        return curr;
    }
};