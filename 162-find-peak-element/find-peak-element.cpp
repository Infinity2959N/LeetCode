class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        // Peak element: before should be smaller, after shoudl be smaller. 
        int left= 0, right= nums.size()-1;

        while(left<right){
            int mid= left+(right-left)/2;
            if(nums[mid]< nums[mid+1]) 
                left= mid+1;
            else
                right= mid;
        }
        return left;
    }
};