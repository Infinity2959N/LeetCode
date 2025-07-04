class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int total= accumulate(nums.begin(), nums.end(), 0);
        if(total%k!=0)  return false;
        int target= total/k;
        sort(nums.rbegin(), nums.rend());   // biggest first

        if(nums[0]> target) return false;

        vector<int> buckets(k, 0);

        return dfs(nums, 0, buckets, target);
    }

private:
    bool dfs(vector<int>& nums, int i, vector<int>& bucket, int target){
        // Base case: we have reached the end of array
        if(i==nums.size()){
            for(int b: bucket){
                if(b!=target)
                    return false;
            }
            return true;
        }

        for(int j=0; j<bucket.size(); j++){
            if(bucket[j]+ nums[i]> target)  continue;   //cannot fit in this bucket
            bucket[j]+= nums[i];    //else if space is there, fill it
            // After putting it inside bucket, we check if it was right choice to put it or not
            if(dfs(nums, i+1, bucket, target))  return true;
            bucket[j]-= nums[i]; //wrong choice
            if(bucket[j]==0)    break;
        }
        return false;
    }
};