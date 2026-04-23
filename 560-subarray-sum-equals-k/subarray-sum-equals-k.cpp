class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // Calculate prefix sum
        int n= nums.size();
        vector<int> prefix(n);
        prefix[0]= nums[0];
        for(int i=1; i<n; i++){
            prefix[i]= prefix[i-1]+ nums[i];
        }
        int num=0;

        // unordered map to store frequency
        unordered_map<int, int> map;

        for(int i=0; i<n; i++){
            // Already k, increase the num
            if(prefix[i]==k) num++;

            // check prefix[i]-k is in the map, increment by frequency
            if(map[prefix[i]-k])
                num+=map[prefix[i]-k];
            
            // Put current sum on map
            map[prefix[i]]++;
        }
        return num;
    }
};