class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;    // target-value, index
        
        for(int i=0; i<nums.size(); i++){
            if(map.count(nums[i])){
                return {map[nums[i]], i};
            }  // we found current value
            else{
                map[target-nums[i]]= i;
            }
        }
        return {-1,-1};
    }
};