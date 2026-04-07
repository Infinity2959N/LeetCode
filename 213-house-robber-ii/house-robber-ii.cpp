class Solution {
public:
    int rob(vector<int>& nums) {
      // House robber variation
      // Trick for circluar: if you start from 0, you won't  be able to rob last house: loop 1: 0->n-2
      // If you want to rob last, go for first house: loop 2: 1->n-1
      int n= nums.size();
      if(n==1)  return nums[0];

      return max(robHouse(nums, 0, n-1), robHouse(nums, 1, n));
    }
private:
    int robHouse(const vector<int>& house, int s, int e){
        // DP cases: for house i, either skip i and take best of i-1, or rob i and take best of i-2
        int prev2= 0;
        int prev1= 0;
        for(int i=s; i<e; i++){
            int curr= max((house[i]+ prev2), prev1);
            prev2= prev1;
            prev1= curr;
        }
        return prev1;
    }
};