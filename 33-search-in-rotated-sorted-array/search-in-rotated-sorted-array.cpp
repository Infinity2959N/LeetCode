class Solution {
public:
    int search(vector<int>& nums, int target) {
        // Binary search with added conditions
        // Think of the array as two arrays. The element would be ine one of the two arrays.
        // When we divide the array with mid, either left or right part will be sorted. We find the sorted part and check if the target lies there, if not found, we move to unsorted part.
        int left= 0, right= nums.size()-1;

        while(left<=right){
            int mid= left+ (right-left)/ 2;
            if(nums[mid]== target)
                return mid;
            else if(nums[mid]>= nums[left]){
                // Means left half is sorted
                if(target>= nums[left] && target< nums[mid])
                    right= mid-1;
                else
                    left= mid+1;
            }else{  // right part is sorted
                if(target> nums[mid] && target<= nums[right])
                    left= mid+1;
                else
                    right= mid-1;
            }
        }

        return -1;
    }
};