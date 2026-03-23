class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        // LIS using binary search: O(nlogn), over O(n^2) in traditional DP
        // Patience Sorting (tails) logic
        // We do not care about the sequence here
        // We try to find smallest possible numbers to form a sequence of length l.
        // Say given an array: 1,7,8,4,5,-1,9
        // 1. Sequence: 1,7,8
        // 2. Using Binary search find the optimal place for 4 and replace: 1,4,8
            // First optimal place would be first element greater than current
            // Use lower bound
        // 3. Keep going: 1,4,5-> -1,4,5-> -1,4,5,9: max length: 4.
        int n= nums.size();
        if(n==1)    return 1;

        vector<int> temp;
        temp.push_back(nums[0]);


        for(int i=1; i<n; i++){
            if(nums[i]> temp.back()){
                temp.push_back(nums[i]);
            }else{
                int idx= lower_bound(temp.begin(), temp.end(), nums[i])- temp.begin();
                temp[idx]= nums[i];
            }
        }

        return temp.size();
    }
};