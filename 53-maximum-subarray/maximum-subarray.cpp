class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currMax= 0, maxTillNow= INT_MIN;
        for(int num: nums){
            currMax= max(num, currMax+ num);
            maxTillNow= max(maxTillNow, currMax);
        }
        return maxTillNow;
    }
};