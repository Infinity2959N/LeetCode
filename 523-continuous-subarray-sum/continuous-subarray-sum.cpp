class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        // Property: 2 prefix sums: Si and Sj, and Si+Sj(mod k)==0; then Sj (mod k)= Si (mod k)
        // Keep a running prefix sum, store prefix sum (mod k) in the hashmap<remainder, index>
        // If you see the same remainder again, it means the elements added between the first time you saw that remainder and now sum up to a multiple of k
        // If difference in indices>=2, return true

        int n= nums.size();
        vector<int> prefix(n);
        prefix[0]= nums[0];
        for(int i=1; i<n; i++){
            prefix[i]= prefix[i-1]+ nums[i];
        }

        unordered_map<int, int> map; // remainder, index
        map[0]= -1;     // Very important line
        //if a prefix sum itself is a multiple of $k$ starting from the very first element, you need a "virtual" index at -1 to satisfy the length>= 2 condition.

        for(int i=0; i<n; i++){
            int rem= prefix[i]%k;
            if(map.count(rem)){
                if(i-map[rem]>=2)return true;
            }else map[rem]= i;
        }
        return false;
    }
};