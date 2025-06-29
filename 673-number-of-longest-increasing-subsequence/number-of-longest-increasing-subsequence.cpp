class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n= nums.size();
        vector<int> lis(n, 1);
        vector<int> count(n, 1);

        for(int i=0; i<n; i++){
            for(int j=0; j<i; j++){
                if(nums[j]< nums[i]){
                    if(lis[i] < lis[j]+1){
                        lis[i]= lis[j]+1;
                        count[i]= count[j];
                    }else if(lis[i] == lis[j]+1){
                        count[i]+= count[j];
                    }
                }
            }
        }
        int maxlen= *max_element(lis.begin(), lis.end());
        int sum=0;
        for(int i=0; i<n; i++){
            if(lis[i]==maxlen){
                sum+= count[i];
            }
        }
        return sum;
    }
};