class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = nums[0];
        int curMax = 1, curMin = 1;

        for (int n : nums) {
            // If n is negative, the potential max and min swap roles
            if (n < 0) swap(curMax, curMin);

            // Three choices: start new at n, multiply existing max by n, or multiply existing min by n
            // Since we swapped for negative n, we just compare n and n*prev
            curMax = max(n, n * curMax);
            curMin = min(n, n * curMin);

            res = max(res, curMax);
        }
        return res;
    }
};
