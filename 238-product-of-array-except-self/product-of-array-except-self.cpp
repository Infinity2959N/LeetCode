class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // Approach: We make a suffix and prefix product array. Final would be suffix*prefix for each element
        int n= nums.size();
        vector<int> res(n, 1);
        // space optimized

        // prefix
        for(int i=1; i<n; i++){
            res[i]= res[i-1]*nums[i-1];
        }

        // prefix * suffix
        int suffix= 1;
        for(int i=n-1; i>=0; i--){
            res[i]*= suffix;
            suffix*= nums[i];
        }
        return res;
    }
};