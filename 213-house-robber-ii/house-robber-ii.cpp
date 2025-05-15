class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        
        // Two scenarios
        int excludeFirst = robLinear(nums, 1, n - 1); // Rob from 1 to n-1
        int excludeLast  = robLinear(nums, 0, n - 2); // Rob from 0 to n-2

        return max(excludeFirst, excludeLast);
    }

private:
    int robLinear(const vector<int>& nums, int start, int end) {
        int prev2 = 0, prev1 = 0;
        for (int i = start; i <= end; ++i) {
            int curr = max(nums[i] + prev2, prev1);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};
