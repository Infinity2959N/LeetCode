class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n= nums.size(), left= 0, right= n-1;
        if(n<2)    return n-1;

        while(left<right){
            int mid= left+(right-left)/2;
            if((mid==0 || nums[mid]>= nums[mid-1]) && (mid==n-1 || nums[mid]>=nums[mid+1]))
                return mid;
            else if(mid>0 && nums[mid] < nums[mid-1])   right=mid-1;
            else    left=mid+1;
        }
        return left;
    }
};