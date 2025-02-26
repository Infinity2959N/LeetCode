class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        
        // The result array
        vector<int> result(n, 1);
        
        // Step 1: Calculate the prefix product (left product)
        int leftProduct = 1;
        for (int i = 0; i < n; ++i) {
            result[i] = leftProduct;
            leftProduct *= nums[i];
        }
        
        // Step 2: Calculate the suffix product (right product) and multiply it with the result array
        int rightProduct = 1;
        for (int i = n - 1; i >= 0; --i) {
            result[i] *= rightProduct;
            rightProduct *= nums[i];
        }
        
        return result;

    }
};