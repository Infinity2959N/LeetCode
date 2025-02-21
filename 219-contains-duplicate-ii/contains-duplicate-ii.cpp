class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        int n=nums.size();
        for(int i=0; i< n; i++){
            int key= nums[i];
            if(map.count(key) && abs(i- map[key]) <=k)   return true;

            map[key]=i;   
        }
        return false;
    }
};