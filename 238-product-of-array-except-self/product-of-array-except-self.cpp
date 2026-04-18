class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // Approach: We make a suffix and prefix product array. Final would be suffix*prefix for each element
        int n= nums.size();
        vector<int> prefix(n, 1);
        for(int i=1; i<n; i++){
            prefix[i]= prefix[i-1]*nums[i-1];
        }

        vector<int> suffix(n, 1);
        for(int i=n-2; i>=0; i--){
            suffix[i]= suffix[i+1]*nums[i+1];
        }
        vector<int> res(n);
        for(int i=0; i<n; i++){
            res[i]= suffix[i]*prefix[i];
        }
        return res;
    }
};