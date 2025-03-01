class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> positive, negative;
        for(int num: nums){
            if(num>0)   positive.push_back(num);
            else    negative.push_back(num);
        }
        int n= positive.size(), m=0;
        for(int i=0; i<n; i++){
            nums[m++]=positive[i];
            nums[m++]=negative[i];
        }

        return nums;
    }
};