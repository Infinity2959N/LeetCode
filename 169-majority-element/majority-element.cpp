class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int i: nums){
            mp[i]++;
        }
        int size=nums.size() / 2;
        for(auto x: mp){
            if(x.second > size){
                return x.first;
            }
        }
        return 0;
    }
};