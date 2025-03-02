class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res;
        int first=-1, second=-1;
        int left= 0, right= nums.size()-1;
        //First occurence
        while(left<=right){
            int mid= left+ (right-left)/2;
            if(nums[mid]==target){
                first=mid;
                right=mid-1;
            }else if(nums[mid]<target){
                left=mid+1;
            }
            else    right=mid-1;
        }
        res.push_back(first);
        left=0, right=nums.size()-1;
        //last occurence
        while(left<=right){
            int mid= left+ (right-left)/2;
            if(nums[mid]==target){
                second=mid;
                left=mid+1;
            }else if(nums[mid]<target){
                left=mid+1;
            }
            else    right=mid-1;
        }
        res.push_back(second);
        return res;
    }
};