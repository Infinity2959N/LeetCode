class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        if (n1 > n2) return findMedianSortedArrays(nums2, nums1);

        int l = 0, r = n1;
        int half = (n1 + n2 + 1) / 2;

        while (l <= r) {
            int i = l + (r - l) / 2;
            int j = half - i;

            // Use i-1 and j-1 for the left side
            double left1 = (i == 0) ? -1e18 : nums1[i - 1]; 
            double right1 = (i == n1) ? 1e18 : nums1[i];
            double left2 = (j == 0) ? -1e18 : nums2[j - 1];
            double right2 = (j == n2) ? 1e18 : nums2[j];

            if (left1 <= right2 && left2 <= right1) {
                // Odd total length
                if ((n1 + n2) % 2 != 0) return max(left1, left2);
                // Even total length
                return (max(left1, left2) + min(right1, right2)) / 2.0;
            } 
            else if (left1 > right2) {
                r = i - 1;
            } else {
                l = i + 1;
            }
        }
        return 0.0;
    }
};