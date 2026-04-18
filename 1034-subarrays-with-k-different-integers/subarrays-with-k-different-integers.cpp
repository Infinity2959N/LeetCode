class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        // Problem with sliding window:
        // While sliding window is really effective in finding "atmost k" type of solutions, but it fails on "count exactly k" type of solution
        // Why? When you have exactly k, moving left might still leace you with k, meaning there are multiple valid subarrays ending at index i
        // Solution: Think of Exactly k= atmost (k)- atmost (k-1)
        
        return AtMostK(nums, k)- AtMostK(nums, k-1);
    }
private:
    int AtMostK(vector<int>& nums, int k){
        unordered_map<int, int> map;
        int count=0;
        int res=0;
        int left=0;
        for(int right=0; right<nums.size(); right++){
            if(map[nums[right]]==0)
                count++;
            map[nums[right]]++;
            
            while(count>k){
                map[nums[left]]--;
                if(map[nums[left]]==0)
                    count--;
                left++;
            }
            // KEY LOGIC: All subarrays ending at 'right' are valid
            // [left...right], [left+1...right], ..., [right...right]
            res+= right-left+1;
        }
        return res;
    }
};