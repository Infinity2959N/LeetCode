class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        // Approach, using binary search to find the possible sum ceil, and then using greedy to find the number of subsets it would take to keep ma sum lower than mid

        int low= *max_element(nums.begin(), nums.end());    // minimum max subset size would be the largest element
        int high= accumulate(nums.begin(), nums.end(), 0);  //max would be the total sum of elements
        int result= high;

        while(low<= high){
            int mid= low+(high-low)/2;

            if(isValid(nums, k, mid)){  // Greedily checks for subsets and returns true if number of subsets formed is <=k
                high= mid-1;
            }else{
                low= mid+1;
            }
        }
        return low;
    }
private:
    bool isValid(vector<int>& nums, int k, int maxAllowedSum){
        int count=1;    // Atleast 1 subarray
        int currSum= 0;

        for(int num: nums){
            if(currSum+ num> maxAllowedSum){
                count++;
                currSum= num;
                if(count> k)    return false;
            }else{
                currSum+= num;
            }
        }
        return true;
    }
};