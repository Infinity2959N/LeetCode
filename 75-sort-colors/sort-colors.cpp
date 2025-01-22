class Solution {
public:
    void sortColors(vector<int>& nums) {
        //use counting sort:
        int num[3]={0};
        for(int i: nums){
            num[i]++;
        }
        int index=0;
        for(int color=0;color<3;color++){
            for(int i=0;i< num[color];i++){
                nums[index++]=color;
            }
        }
    }
};