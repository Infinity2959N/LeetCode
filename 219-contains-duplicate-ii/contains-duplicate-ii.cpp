class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        for(int i=0; i<nums.size(); i++){
            int key= nums[i];
            if(map.count(key) && abs(i- map[key]) <=k)   return true;

            map[key]=i;   
        }
        return false;
    }
};