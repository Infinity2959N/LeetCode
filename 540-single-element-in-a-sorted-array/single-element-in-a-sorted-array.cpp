class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int low=0, high=nums.size()-1;
        if(high==0 || nums[low]!=nums[low+1]){
            return nums[0];
        }
        //The position of second element will tell whether it's the left side or the right
        while(low<=high){
            int mid = low + (high - low) / 2;
            if (nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1]) return nums[mid];
            if ((mid % 2 == 0 && nums[mid] == nums[mid + 1])
             || (mid % 2 == 1 && nums[mid] == nums[mid - 1])) low = mid +1;
            else high = mid - 1;
        }
        return 0;
    }
};