class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        // Approach: 2 binary searchs, one for leftmost and other for rightmost occurence
        int left= 0, right= nums.size()-1;
        int lo= -1, ro=-1;     // leftoccurence and rightoccurene
        // Left occurence
        while(left<=right){
            int mid= left+ (right- left)/ 2;
            if(nums[mid]> target){
                right= mid-1;
            }else if(nums[mid]==target){
                lo=mid;
                right= mid-1;
            }else{
                left= mid+1;
            }
        }
        left= 0, right= nums.size()-1;
        while(left<=right){
            int mid= left+ (right- left)/ 2;
            if(nums[mid]> target){
                right= mid-1;
            }else if(nums[mid]==target){
                ro=mid;
                left= mid+1;
            }else{
                left= mid+1;
            }
        }

        return {lo, ro};
    }
};