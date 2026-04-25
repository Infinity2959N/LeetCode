class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();

        // 1. Sanitize: Remove non-useful numbers
        for (int i = 0; i < n; i++) {
            if (nums[i] <= 0 || nums[i] > n) {
                nums[i] = n + 1;
            }
        }

        // 2. Mark: Use index as hash key
        for (int i = 0; i < n; i++) {
            int val = abs(nums[i]);
            if (val <= n) {
                int idx = val - 1;
                // Only flip if it's currently positive to avoid double-negatives
                if (nums[idx] > 0) {
                    nums[idx] *= -1;
                }
            }
        }

        // 3. Find: The first positive index
        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) return i + 1;
        }

        return n + 1;
    }
};